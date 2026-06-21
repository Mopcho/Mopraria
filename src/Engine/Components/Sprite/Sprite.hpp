#pragma once
#include <raylib.h>
#include <string>

namespace ME {
    class Sprite2D {
    public:
        Sprite2D();
        Texture2D texture;
        Rectangle sourceRectangle;
    };
}