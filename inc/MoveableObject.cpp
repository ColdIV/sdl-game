#include "MoveableObject.h"

int32_t MoveableObject::getSpeed () {
    return this->speed;
}

float MoveableObject::getAngle () {
    return this->angle;
}

float MoveableObject::getTurnSpeed () {
    return this->turnSpeed;
}

void MoveableObject::setSpeed (int32_t speed) {
    this->speed = speed;
}

void MoveableObject::setAngle (float angle) {
    this->angle = angle;
}

void MoveableObject::setTurnSpeed (float turnSpeed) {
    this->turnSpeed = turnSpeed;
}

void MoveableObject::turn (int32_t direction) {
    this->angle += this->getTurnSpeed() * direction;
    if (this->angle > 628319) this->angle /= 100000;
}

SDL_Point MoveableObject::move (int32_t direction) {
    SDL_Point tPos = this->getPosition();
    int32_t x, y;
    // To be honest: I don't know why I need the `.5 +` here. If you do, please tell me.
    // I assume it's because of the conversion to `int32_t` and with the `.5` added it rounds correctly.
    // I just happened to find this when I was debugging an error where the player always drifts towards the upper left corner.
    x = .5 + tPos.x + (cos(this->getAngle()) * this->getSpeed()) * direction;
    y = .5 + tPos.y + (sin(this->getAngle()) * this->getSpeed()) * direction;
    
    return {x, y};
}

void MoveableObject::draw (SDL_Renderer *renderer, SDL_Point gVPosition, int32_t gVWidth, int32_t gVHeight) {
    if (this->getTexture() == nullptr) {
        this->loadTexture(renderer);
    }

    int32_t w, h;
	SDL_Point p;

    SDL_Rect Object_r;
	p = this->getPosition();
	w = this->getWidth();
	h = this->getHeight();

    // Translate coordinates according to gameViev
    p.x -= gVPosition.x;
    p.y -= gVPosition.y;

	Object_r.x = p.x;
	Object_r.y = p.y;
	Object_r.w = w;
	Object_r.h = h;

    p.x = w / 2;
    p.y = h / 2;

    SDL_RenderCopyEx(renderer, this->getTexture(), NULL, &Object_r, this->angle * 180.0 / M_PI, &p, SDL_FLIP_NONE);


    // Debug
    SDL_Point move_p = this->move(1);
    SDL_Rect move_r;
    move_r.x = move_p.x - gVPosition.x + w / 2;
    move_r.y = move_p.y - gVPosition.y + h / 2;
    move_r.w = 5;
    move_r.h = 5;

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &move_r);
}