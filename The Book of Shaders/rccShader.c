#include "libs/rccShader.h"
#include <stdio.h>
#include <stdlib.h>

char* readShaderSource(const char* filePath) {
    FILE* file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "Erro ao abrir arquivo: %s\n", filePath);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* source = (char*)malloc(length + 1);
    if (source == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o shader.\n");
        fclose(file);
        return NULL;
    }

    size_t bytesRead = fread(source, 1, length, file);
    if (bytesRead != length) {
        fprintf(stderr, "Erro ao ler o arquivo. Esperado %ld, mas leu %zu.\n", length, bytesRead);
    }

    if (source[bytesRead - 1] == '\n') {
        source[bytesRead - 1] = '\0';  // Remove o '\n' no final
    }
    if (source[bytesRead - 1] == '\r') {
        source[bytesRead - 1] = '\0';  // Remove o '\r' no final
    }

    source[bytesRead] = '\0'; 
    fclose(file);

    return source;
}

GLuint compileShader(const char* source, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        fprintf(stderr, "Erro ao compilar shader: %s\n", infoLog);
    }
    return shader;
}

GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath) {
    char* vertexSource = readShaderSource(vertexPath);
    char* fragmentSource = readShaderSource(fragmentPath);

    if(!vertexSource || !fragmentSource) {
        fprintf(stderr, "Erro ao ler arquivos de shader. \n");
        return 0;
    }

    GLuint vertexShader = compileShader(vertexSource, GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(fragmentSource, GL_FRAGMENT_SHADER);
    GLuint shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    GLuint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        fprintf(stderr, "Erro ao linkar o programa de shader: %s\n", infoLog);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    free(vertexSource);
    free(fragmentSource);

    return shaderProgram;
}