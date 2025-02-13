#ifndef R_TEXT_H
#define R_TEXT_H

#include <ft2build.h>
#include FT_FREETYPE_H

typedef struct {
    unsigned int texture_id;
    int width;
    int height;
    int bearing_x;
    int bearing_y;
    unsigned int advance;
} Character;

int initFreeType(const char* filepath);
void renderText(const char* text, float x, float y, float scale, float r, float g, float b);
void cleanupText();

#endif // R_TEXT_H