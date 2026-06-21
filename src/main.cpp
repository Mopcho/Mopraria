#include <iostream>
#include <raylib.h>
#include <iostream>
#include "Textures.hpp"
#include "Block.hpp"
#include "Constants.hpp"
#include "Engine/Window/Window.hpp"

int main() {
    ME::SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    ME::InitWindow(800, 600, "Mopraria");
    ME::MaximizeWindow();

    Textures& textures_instance = Textures::instance();
    textures_instance.load();

    ME::SetTargetFPS(60);
    while (!ME::WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            Block block1{Vector2{0, 0}, textures_instance.g_textures[BlockIds::DeepslateBricks]};
            Block block2{Vector2{2, 2}, textures_instance.g_textures[BlockIds::DeepslateBricks]};
            block1.render();
            block2.render();
        EndDrawing();
    }
    
    ME::CloseWindow();

    return 0;
}