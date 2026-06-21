#pragma once
#include <raylib.h>

namespace ME {
    class Transform {
    public:
        Transform();

        Vector2 position;
        int rotation;
        Vector2 scale;
    };
}