#include "Block.hpp"

Block::Block(Vector2 gridPos, G_Texture g_texture) {
    int screenWidth = GetScreenWidth();
    int frameWidth = g_texture.texture.width;
    int frameHeight = g_texture.texture.height;

    texture = g_texture.texture;
    origin = { (float)frameWidth, (float)frameHeight };
    rotation = 0;
    sourceRec = { g_texture.sourceRec.x, g_texture.sourceRec.y, g_texture.width, g_texture.heigth };
    destRec = { gridPos.x * screenWidth / 16 , gridPos.y * screenWidth / 16, screenWidth / 16.0f, screenWidth / 16.0f };
}
