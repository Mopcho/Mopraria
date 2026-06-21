#include "Transform.hpp"

ME::Transform::Transform()
{
}

ME::Transform::Transform(Vector2 position, int rotation, Vector2 scale, float width, float height) : 
    position(position), 
    rotation(rotation), 
    scale(scale),
    width(width), 
    height(height)
{
}
