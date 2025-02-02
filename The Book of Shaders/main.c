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

    printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
    printf("GLSL Version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

    const char* glslVersion = (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);
    printf("GLSL Version: %s\n", glslVersion);


    GLuint shaderProgram = createShaderProgram("vertex_shader.glsl", "fragment_shader.glsl");
    glUseProgram(shaderProgram);

/*______________________________________________________________________________*/ 

    float vertices[] = {
        -1.0f, -1.0f,  
        1.0f, -1.0f,  
        -1.0f,  1.0f,  

        -1.0f,  1.0f,  
        1.0f, -1.0f,  
        1.0f,  1.0f  
    };

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

/*______________________________________________________________________________*/ 

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        //  Render
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}