#include "Animation.hpp"
#include <iostream>

ME::Animation::Animation()
{
}

void ME::Animation::SetSprite(std::shared_ptr<ME::Sprite2D> sprite)
{
    m_sprite = sprite;
}

void ME::Animation::Play()
{
    playing = true;
    current_frame = 0;
    m_elapsedTime = 0.0f;

    // Setup first frame
    float new_x = offset_x + width;
    float new_y = offset_y;
    m_sprite->sourceRectangle = Rectangle{ new_x, new_y, width, height };
}

void ME::Animation::Stop()
{
    playing = false;
    current_frame = 0;
    m_elapsedTime = 0.0f;
}

void ME::Animation::Update(float delta_time)
{
    if (!playing) {
        return;
    }

    m_elapsedTime += delta_time;

    if (m_elapsedTime < animation_speed) {
        return;
    }

    float new_x = offset_x + ( current_frame * width );
    float new_y = offset_y;
    m_sprite->sourceRectangle = Rectangle{ new_x, new_y, width, height };
    current_frame++;
    m_elapsedTime = 0.0f;
    if (current_frame >= frames) {
        if (!repeat) {
            Stop();
        } else {
            Play();
        }
    }
}
