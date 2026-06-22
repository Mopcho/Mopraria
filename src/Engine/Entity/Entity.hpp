#pragma once
#include "Engine/Components/Transform/Transform.hpp"
#include "Engine/Components/Sprite/Sprite.hpp"
#include <memory>

namespace ME {
    class Entity {
    public:
        Entity();
        std::shared_ptr<ME::Transform> transform;
        std::shared_ptr<ME::Sprite2D> sprite;

        void Draw();
    };
}