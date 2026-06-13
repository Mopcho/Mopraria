#include "Textures.hpp"
#include <iostream>
#include "Constants.hpp"
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

void Textures::load() {
    std::ifstream textures_metadata_file{TEXTURES_METADATA_JSON_PATH};
    json textures_metadata = json::parse(textures_metadata_file);

    // Load Blocks
    json blocks = textures_metadata["blocks"];
    for (auto& block : blocks) {
        std::filesystem::path texture_path = TEXTURES_FOLDER_PATH / block["path"];
        Texture2D texture = LoadTexture(texture_path.string().c_str());
        g_textures[block["id"]] = G_Texture{texture, Vector2{block["source_x"], block["source_y"]}, block["width"], block["height"]};
    }

    all_loaded = true;
}