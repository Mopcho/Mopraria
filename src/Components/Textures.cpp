#include "Textures.hpp"
#include <iostream>
#include "constants.hpp"

void Textures::load() {
    std::filesystem::path black_stone_texture_path = TEXTURES_FOLDER_PATH / "separate/texture_16px_1.png";
    Texture2D black_stone_texture = LoadTexture(black_stone_texture_path.string().c_str());
    black_stone = G_Texture{black_stone_texture, Vector2{0.0f, 0.0f}, (float)black_stone_texture.width, (float)black_stone_texture.height };

    all_loaded = true;
}