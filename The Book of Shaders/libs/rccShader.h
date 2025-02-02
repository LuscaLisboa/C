#ifndef RCC_SHADER_H
#define RCC_SHADER_H

#include <GL/glew.h>

char* readShaderSource(const char* filepath);
GLuint compileShader(const char* filepath, GLenum type);
GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath);

#endif // RCC_SHADER_H