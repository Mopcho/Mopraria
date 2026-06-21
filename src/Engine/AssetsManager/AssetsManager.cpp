#include "AssetsManager.hpp"
#include <iostream>

Texture2D ME::AssetsManager::GetTexture(std::string_view key)
{
    return textures.at(key.data());
}

void ME::AssetsManager::LoadTexture(std::string key, std::string_view path)
{
    if (textures.find(key) != textures.end()) {
        std::cout << "Warning: Texture with key: " << key << " already exists. Skipping load." << std::endl; 
        return;
    } 

    Texture2D texture = ::LoadTexture(path.data());
    textures[key] = texture;
}
