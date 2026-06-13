#pragma once
#include <raylib.h>
#include <unordered_map>

struct G_Texture {
    Texture2D texture;
    Vector2 sourceRec;
    float width;
    float heigth;
};

class Textures {
public:
    static Textures& instance() {
        static Textures instance;
        return instance;
    }

    void load();

    std::unordered_map<int, G_Texture> g_textures;

    bool all_loaded = false;

private:
    Textures() = default;

    // Prevent copies
    Textures(const Textures&) = delete;
    Textures& operator=(const Textures&) = delete;
};