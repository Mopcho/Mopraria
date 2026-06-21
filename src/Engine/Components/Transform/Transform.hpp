#pragma once
#include <raylib.h>

namespace ME {
    class Transform {
    public:
        Transform();
        Transform(Vector2 position, int rotation, Vector2 scale, float width, float height);

        Vector2 position = Vector2{0, 0};
        int rotation = 0;
        Vector2 scale = Vector2{0, 0};
        float width = 0;
        float height = 0;
        Vector2 origin = Vector2{0, 0};
    };
}