#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "libs/rccShader.h"
#include <stdio.h>

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

    GLuint shaderProgram = createShaderProgram("vertex_shader.glsl", "fragment_shader.glsl");
    glUseProgram(shaderProgram);

    float vertices[] = {
        -1.0f, -1.0f,  
        1.0f, -1.0f,  
        -1.0f,  1.0f,  

        -1.0f,  1.0f,  
        1.0f, -1.0f,  
        1.0f,  1.0f  
    };

    

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        //  Render

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}