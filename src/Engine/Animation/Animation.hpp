#pragma once
#include <memory>
#include "Engine/Components/Sprite/Sprite.hpp"

namespace ME {
    class Animation {
    public:
        Animation();

        void SetSprite(std::shared_ptr<ME::Sprite2D> sprite);
        void Play();
        void Stop();
        void Update(float delta_time);

        bool repeat = false;
        float offset_x = 0.0f;
        float offset_y = 0.0f;
        float width = 0.0f;
        float height = 0.0f;
        int frames = 0;
        float animation_speed = 1.0f;
        float m_elapsedTime = 0.0f;

        int current_frame = 0;
        bool playing = false;
    private:
        std::shared_ptr<ME::Sprite2D> m_sprite;
    };
}