#include "Entity.hpp"

ME::Entity::Entity()
{
    transform = ME::Transform();
    sprite = ME::Sprite2D();
}

void ME::Entity::Draw()
{
    DrawTexturePro(
        sprite.texture, 
        sprite.sourceRectangle, 
        Rectangle{transform.position.x, transform.position.y, transform.width, transform.height},
        transform.origin,
        transform.rotation,
        WHITE
    );
}
