#include "types.hpp"
#include "BlackStone.hpp"
#include "Textures.hpp"

BlockType GetBlackStone(Vector2 gridPos) {
    int screenWidth = GetScreenWidth();
    Texture2D texture = Textures::instance().black_stone;
    int frameWidth = texture.width;
    int frameHeight = texture.height;
    Vector2 origin = { (float)frameWidth, (float)frameHeight };
    int rotation = 0;
    Rectangle sourceRec = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };
    Rectangle destRec = { gridPos.x * screenWidth / 16 , gridPos.y * screenWidth / 16, screenWidth / 16, screenWidth / 16 };

    return BlockType{ texture, sourceRec, destRec, origin, rotation, WHITE };
}