#include "Object.h"

Object::Object () {}

Object::Object (SDL_Point position, int32_t width, int32_t height) {
    this->position = position;
    this->width = width;
    this->height = height;
}

Object::~Object () {
    if (this->texture != nullptr) {
        SDL_DestroyTexture(this->texture);
    }
}

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

SDL_Texture* Object::getTexture () const {
    return this->texture;
}

void Object::setWidth (int32_t width) {
    this->width = width;
}

void Object::setHeight (int32_t height) {
    this->height = height;
}

void Object::setImagePath (const char* path) {
    this->imagePath = path;
}
#include <iostream>
void Object::loadTexture (SDL_Renderer *renderer) {
    SDL_Surface *image = IMG_Load(this->imagePath);
    
    if (image != nullptr) {
        this->texture = SDL_CreateTextureFromSurface(renderer, image);
        SDL_FreeSurface(image);
    } else {
        std::cout << "IMG_Load: " << IMG_GetError() << "\n";
    }
}

void Object::draw (SDL_Renderer *renderer, SDL_Point gVPosition, int32_t gVWidth, int32_t gVHeight) {
    if (this->texture == nullptr) {
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

    SDL_RenderCopy(renderer, this->texture, NULL, &Object_r);
}