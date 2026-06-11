#pragma once

#include <raylib.h>

struct BlockType {
    Texture2D texture;
    Rectangle sourceRec;
    Rectangle destRec;
    Vector2 origin;
    int rotation;
    CLITERAL(Color) color;
};