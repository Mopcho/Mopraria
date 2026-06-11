#pragma once
#include <raylib.h>

class Textures {
public:
    static Textures& instance() {
        static Textures instance;
        return instance;
    }

    void load();

    Texture2D black_stone{};
    bool all_loaded = false;

private:
    Textures() = default;

    // Prevent copies
    Textures(const Textures&) = delete;
    Textures& operator=(const Textures&) = delete;
};