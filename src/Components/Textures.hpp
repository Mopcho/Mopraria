#pragma once
#include <raylib.h>

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

    G_Texture black_stone{};
    bool all_loaded = false;

private:
    Textures() = default;

    // Prevent copies
    Textures(const Textures&) = delete;
    Textures& operator=(const Textures&) = delete;
};