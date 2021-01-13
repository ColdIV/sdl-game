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

int32_t Player::getSpeed () {
    return this->speed;
}

void Player::move (int32_t x, int32_t y) {
    this->position.x += x;
    this->position.y += y;
}

// You are supposed to call this with 1 or 0s only
// But you can of course move by multiples...
void Player::move (int32_t w, int32_t a, int32_t s, int32_t d) {
    // reverse direction
    w *= -1; a *= -1;
    this->position.x += this->speed * a + this->speed * d;
    this->position.y += this->speed * w + this->speed * s;
}

void Player::draw (SDL_Renderer *renderer) {
    int32_t w, h;
	SDL_Point p;

    SDL_Rect player_r;
	p = this->getPosition();
	w = this->getWidth();
	h = this->getHeight();
	player_r.x = p.x;
	player_r.y = p.y;
	player_r.w = w;
	player_r.h = h;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &player_r);
}