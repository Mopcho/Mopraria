#pragma once
#include "Engine/Components/Transform/Transform.hpp"
#include "Engine/Components/Sprite/Sprite.hpp"

namespace ME {
    class Entity {
    public:
        Entity();
        ME::Transform transform;
        ME::Sprite2D sprite;

        void Draw();
    };
}