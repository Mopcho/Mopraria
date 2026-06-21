#include "Window.hpp"

void ME::InitWindow(int width, int height, const char *title)
{
    ::InitWindow(width, height, title);
}

void ME::CloseWindow()
{
    ::CloseWindow();
}

void ME::MaximizeWindow()
{
    ::MaximizeWindow();
}

void ME::SetConfigFlags(unsigned int flag)
{
    ::SetConfigFlags(flag);
}

void ME::SetTargetFPS(int fps)
{
    ::SetTargetFPS(fps);
}

bool ME::WindowShouldClose()
{
    return ::WindowShouldClose();
}
