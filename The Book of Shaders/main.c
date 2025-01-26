#include <GLFW/glfw3.h>
#include <stdio.h>

int main(void) {
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

    // Define as cores do glClear (isso é o fundo da janela antes de usar shaders)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}