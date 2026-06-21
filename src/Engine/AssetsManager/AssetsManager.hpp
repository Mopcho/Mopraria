#pragma once
#include <unordered_map>
#include <raylib.h>
#include <string>
namespace ME {
    class AssetsManager {
    public:
        Texture2D GetTexture(const std::string& key);
        void LoadTexture(std::string key, std::string_view path);
    private:
        std::unordered_map<std::string, Texture2D> textures;
    };
}