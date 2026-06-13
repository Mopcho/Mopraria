#include "Renderable.hpp"

void Renderable::render()
{
    DrawTexturePro(texture, sourceRec, destRec, origin, rotation, color);
}