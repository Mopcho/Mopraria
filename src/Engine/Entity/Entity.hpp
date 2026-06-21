#pragma once
#include "Components/Transform/Transform.hpp"
#include "Components/Sprite/Sprite.hpp"

namespace ME {
    class Entity {
    public:
        Entity();
        ME::Transform transform;
        ME::Sprite2D sprite;
    };
}