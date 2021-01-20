#include "CollidableObject.h"

CollidableObject::CollidableObject () {}

CollidableObject::CollidableObject (const Object &object) {
    this->setWidth(object.getWidth());
    this->setHeight(object.getHeight());
    this->setPosition(object.getPosition());
}

bool CollidableObject::collidesWithRect (SDL_Point position, int32_t width, int32_t height) {
    SDL_Point tPos = this->getPosition();
    int32_t tWidth = this->getWidth();
    int32_t tHeight = this->getHeight();

    return (tPos.x < position.x + width &&
            tPos.x + tWidth > position.x &&
            tPos.y < position.y + height &&
            tPos.y + tHeight > position.y);
}