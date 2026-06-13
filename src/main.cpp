#include <iostream>
#include <raylib.h>
#include <iostream>
#include "Textures.hpp"
#include "Block.hpp"
#include "Constants.hpp"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Mopraria"); // temporary size
    MaximizeWindow();

    Textures& textures_instance = Textures::instance();
    textures_instance.load();

    int currentMonitor = GetCurrentMonitor();

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            Block block1{Vector2{0, 0}, textures_instance.g_textures[BlockIds::DeepslateBricks]};
            Block block2{Vector2{2, 2}, textures_instance.g_textures[BlockIds::DeepslateBricks]};
            block1.render();
            block2.render();
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}