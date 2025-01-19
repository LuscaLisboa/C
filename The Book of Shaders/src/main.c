#include <GLFW/glfw3.h>
#include <stdio.h>

int main() {
    if (!glfwInit()) {
        printf("Falha ao inicializar GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Teste OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        printf("Falha ao criar janela\n");
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}