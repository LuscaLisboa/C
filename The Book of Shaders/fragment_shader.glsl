#version 460 core
out vec4 FragColor;

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;  // Canvas size (width,height)
uniform vec2 u_mouse;       // mouse position in screen pixels
uniform float u_time;       // Time in seconds since load

vec3 red();

void main() {
    FragColor = vec4(red(), 1.0);
}

vec3 red() {
    return vec3(1.0, 0.0, 0.0);
}