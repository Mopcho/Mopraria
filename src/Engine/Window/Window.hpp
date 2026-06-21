#pragma once
#include <raylib.h>

namespace ME {
    using ConfigFlags = ::ConfigFlags;
    void InitWindow(int width, int height, const char* title);
    void CloseWindow();
    void MaximizeWindow();
    void SetConfigFlags(unsigned int flag);
    void SetTargetFPS(int fps);
    bool WindowShouldClose();
}