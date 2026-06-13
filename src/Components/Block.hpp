#pragma once
#include "Renderable.hpp"

class Block : public Renderable {
public:
    Block(Vector2 gridPos, G_Texture g_texture);
};