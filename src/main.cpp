#include <iostream>
#include <raylib.h>
#include <iostream>
#include "Textures.hpp"
#include "Block.hpp"

int screenWidth;
int screenHeight;

void onWindowResized();

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Mopraria"); // temporary size
    MaximizeWindow();

    Textures& textures_instance = Textures::instance();
    textures_instance.load();

    int currentMonitor = GetCurrentMonitor();
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            if (IsWindowResized()) {
                onWindowResized();
            }
            Block block1{Vector2{0, 0}, textures_instance.black_stone};
            Block block2{Vector2{2, 2}, textures_instance.black_stone};
            block1.render();
            block2.render();
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}

void onWindowResized() {
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
}