#pragma once

#include <raylib.h>
#include "Textures.hpp"

class Renderable {
public:
    void render();

    Texture2D texture;
    Rectangle sourceRec;
    Rectangle destRec;
    Vector2 origin;
    int rotation;
    CLITERAL(Color) color;
};