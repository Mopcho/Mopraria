#include <iostream>
#include <raylib.h>
#include <iostream>
#include "BlackStone.hpp"
#include "types.hpp"
#include "Textures.hpp"

int screenWidth;
int screenHeight;

void onWindowResized();

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Mopraria"); // temporary size
    MaximizeWindow();

    Textures::instance().load();

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
            BlockType block = GetBlackStone(Vector2{0, 0});
            BlockType block2 = GetBlackStone(Vector2{2, 2});
            DrawTexturePro(block.texture, block.sourceRec, block.destRec, block.origin, block.rotation, block.color); 
            DrawTexturePro(block2.texture, block2.sourceRec, block2.destRec, block2.origin, block2.rotation, block2.color); 
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}

void onWindowResized() {
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
}