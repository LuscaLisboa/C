#include "libs/rText.h"

#include <ft2build.h>
#include FT_FREETYPE_H
#include <GL/glew.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 128

static FT_Library library;
static FT_Face face;
static Character characters[MAX_CHARS];
static GLuint VAO, VBO;
static GLuint textShaderProgram;

// Vertex shader para texto
const char* textVertexShader = 
    "#version 330 core\n"
    "layout (location = 0) in vec4 vertex;\n"
    "out vec2 TexCoords;\n"
    "uniform mat4 projection;\n"
    "void main() {\n"
    "    gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);\n"
    "    TexCoords = vertex.zw;\n"
    "}\0";

// Fragment shader para texto
const char* textFragmentShader = 
    "#version 330 core\n"
    "in vec2 TexCoords;\n"
    "out vec4 color;\n"
    "uniform sampler2D text;\n"
    "uniform vec3 textColor;\n"
    "void main() {\n"
    "    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);\n"
    "    color = vec4(textColor, 1.0) * sampled;\n"
    "}\0";

static GLuint createShader(const char* source, GLenum type) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    char infoLog[512];
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("Erro na compilação do shader: %s\n", infoLog);
        return 0;
    }
    return shader;
}

int initFreeType(const char* filepath) {
    // Inicializa FreeType
    if(FT_Init_FreeType(&library)) {
        fprintf(stderr, "Erro ao inicializar FreeType\n");
        return -1;
    }

    // Carrega a fonte
    if(FT_New_Face(library, filepath, 0, &face)) {
        fprintf(stderr, "Erro ao carregar fonte\n");
        return -1;
    }

    FT_Set_Pixel_Sizes(face, 0, 48);

    // Configura OpenGL para renderização de texto
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // Carrega todos os caracteres
    for(unsigned char c = 0; c < MAX_CHARS; c++) {
        if(FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            fprintf(stderr, "Erro ao carregar caractere %c\n", c);
            continue;
        }

        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );

        // Configura parâmetros da textura
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Armazena caractere
        Character character = {
            texture,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            face->glyph->bitmap_left,
            face->glyph->bitmap_top,
            face->glyph->advance.x
        };
        characters[c] = character;
    }

    // Cria e configura VAO/VBO para renderização de texto
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    GLuint vertexShader = createShader(textVertexShader, GL_VERTEX_SHADER);
    GLuint fragmentShader = createShader(textFragmentShader, GL_FRAGMENT_SHADER);

    textShaderProgram = glCreateProgram();
    glAttachShader(textShaderProgram, vertexShader);
    glAttachShader(textShaderProgram, fragmentShader);
    glLinkProgram(textShaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return 0;
}

void renderText(const char* text, float x, float y, float scale, float r, float g, float b) {
    if (!face || !library) {
        fprintf(stderr, "FreeType não foi inicializado corretamente\n");
        return;
    }
    
    glUseProgram(textShaderProgram);
    glUniform3f(glGetUniformLocation(textShaderProgram, "textColor"), r, g, b);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(VAO);

    const char* c;
    for(c = text; *c; c++) {
        Character ch = characters[(int)*c];

        float xpos = x + ch.bearing_x * scale;
        float ypos = y - (ch.height - ch.bearing_y) *scale;

        float w = ch.width * scale;
        float h = ch.height *scale;

        // Att VBO para cada char
        float vertices[6][4] = {
            { xpos, ypos + h, 0.0f, 0.0f },
            { xpos, ypos, 0.0f, 1.0f },
            { xpos + w, ypos, 1.0f, 1.0f },

            { xpos, ypos + h, 0.0f, 0.0f },
            { xpos + w, ypos, 1.0f, 1.0f },
            { xpos + w, ypos + h, 1.0f, 0.0f }
        };

        // Render glifo
        glBindTexture(GL_TEXTURE_2D, ch.texture_id);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // Avança cursor para o próximo glifo??
        x += (ch.advance >> 6) * scale;
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D,0);
}

void cleanupText() {
    for(int i = 0; i < MAX_CHARS; i++) {
        glDeleteTextures(1, &characters[i].texture_id);
    }
    FT_Done_Face(face);
    FT_Done_FreeType(library);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(textShaderProgram);
}