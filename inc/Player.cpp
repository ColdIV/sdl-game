#include "Player.h"

Player::Player () {}

Player::Player (SDL_Point position, int32_t width, int32_t height) {
    this->position = position;
    this->width = width;
    this->height = height;
}

Player::~Player () {}

SDL_Point Player::getPosition () {
    return this->position;
};

int32_t Player::getWidth () {
    return this->width;
}

int32_t Player::getHeight () {
    return this->height;
}