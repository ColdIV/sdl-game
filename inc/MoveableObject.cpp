#include "MoveableObject.h"

int32_t MoveableObject::getSpeed () {
    return this->speed;
}

void MoveableObject::setSpeed (int32_t speed) {
    this->speed = speed;
}

void MoveableObject::move (int32_t x, int32_t y) {
    SDL_Point tPos = this->getPosition();
    this->setPosition(tPos.x + x, tPos.y + y);
}

// You are supposed to call this with 1 or 0s only
// But you can of course move by multiples...
void MoveableObject::move (int32_t w, int32_t a, int32_t s, int32_t d) {
    // reverse direction
    w *= -1; a *= -1;

    SDL_Point tPos = this->getPosition();

    int32_t x = tPos.x + this->speed * a + this->speed * d;
    int32_t y = tPos.y + this->speed * w + this->speed * s;
    
    this->setPosition(x, y);
}