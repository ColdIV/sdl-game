#include "Object.h"

Object::Object () {}

Object::Object (SDL_Point position, int32_t width, int32_t height) {
    this->position = position;
    this->width = width;
    this->height = height;
}

Object::~Object () {}

SDL_Point Object::getPosition () const {
    return this->position;
}

void Object::setPosition (int32_t x, int32_t y) {
    this->position.x = x;
    this->position.y = y;
}

void Object::setPosition (SDL_Point position) {
    this->position = position;
}

int32_t Object::getWidth () const {
    return this->width;
}

int32_t Object::getHeight () const {
    return this->height;
}

void Object::setWidth (int32_t width) {
    this->width = width;
}

void Object::setHeight (int32_t height) {
    this->height = height;
}

bool Object::collidesWithRect (SDL_Point position, int32_t width, int32_t height) {
    SDL_Point tPos = this->getPosition();
    int32_t tWidth = this->getWidth();
    int32_t tHeight = this->getHeight();

    return (tPos.x < position.x + width &&
            tPos.x + tWidth > position.x &&
            tPos.y < position.y + height &&
            tPos.y + tHeight > position.y);
}

void Object::draw (SDL_Renderer *renderer, SDL_Point gVPosition, int32_t gVWidth, int32_t gVHeight) {
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

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &Object_r);
}