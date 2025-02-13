#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "libs/rccShader.h"

#include <ft2build.h>
#include FT_FREETYPE_H
#include "libs/rText.h"

#include <stdio.h>

#define APTOS_DISPLAY "fonts/Aptos/Aptos-Display.ttf"

int main() {
    if (!glfwInit()) {
        printf("Falha ao inicializar GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Teste GLFW", NULL, NULL);
    if (!window) {
        glfwTerminate();
        printf("Falha ao criar janela GLFW\n");
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK) {
        fprintf(stderr, "Erro ao inicializar GLEW\n");
        return -1;
    }

    printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
    printf("GLSL Version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

    const char* glslVersion = (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);
    printf("GLSL Version: %s\n", glslVersion);

    // Inicializa a fonte
    if(initFreeType(APTOS_DISPLAY) != 0) {
        fprintf(stderr, "Erro ao carregar fonte\n");
        return -1;
    }

    GLuint shaderProgram = createShaderProgram("vertex_shader.glsl", "fragment_shader.glsl");
    glUseProgram(shaderProgram);

/*______________________________________________________________________________*/ 

    float vertices[] = {
        -1.0f, -1.0f,   // 0    Inf esq
        1.0f, -1.0f,    // 1    Inf dir
        -1.0f,  1.0f,   // 2    Sup esq
        1.0f,  1.0f,    // 3    Sup dir 
    };

    unsigned int indices[] = {
        0, 1, 2,    // 1° Triângulo
        2, 3, 0     // 2° Triângulo
    };

    GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

/*______________________________________________________________________________*/ 

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        //  Render
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // rText.c
        renderText("Comi seu pai", -0.5f, 0.0f, 0.002f, 1.0f, 1.0f, 1.0f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    cleanupText(); // rText.c

    glfwTerminate();

    return 0;
}