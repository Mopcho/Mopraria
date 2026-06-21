#pragma once
#include <raylib.h>

namespace ME {
    class Camera2D {
    public:
        Camera2D();

        Vector2 target;
        Vector2 offset;
        float rotation;
        float zoom;
    private:
        ::Camera2D camera;
    };
}