#include "World.h"

World::World () {}
        
World::World (SDL_Point position, int32_t width, int32_t height) {
    this->position = position;
    this->width = width;
    this->height = height;
}

World::~World () {}

SDL_Point World::getPosition () {
    return this->position;
};

int32_t World::getWidth () {
    return this->width;
}

int32_t World::getHeight () {
    return this->height;
}