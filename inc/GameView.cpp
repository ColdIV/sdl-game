#include "GameView.h"

GameView::GameView () {
    this->position = { 0, 0 };
    this->width = 0;
    this->height = 0;
}
        
GameView::GameView (SDL_Point position, int32_t width, int32_t height) {
    this->position = position;
    this->width = width;
    this->height = height;
}

GameView::~GameView () {}

SDL_Point GameView::getPosition () {
    return this->position;
};

int32_t GameView::getWidth () {
    return this->width;
}

int32_t GameView::getHeight () {
    return this->height;
}

void GameView::move (SDL_Point position, int32_t width, int32_t height) {
    if (position.x - this->paddingX < this->position.x) {
        this->position.x = position.x - this->paddingX;
    } else if (position.x + width + this->paddingX > this->position.x + this->getWidth()) {
        this->position.x += (position.x + width + this->paddingX) - (this->position.x + this->getWidth());
    }

    if (position.y - this->paddingY < this->position.y) {
        this->position.y = position.y - this->paddingY;
    } else if (position.y + height + this->paddingY > this->position.y + this->getHeight()) {
        this->position.y += (position.y + height + this->paddingY) - (this->position.y + this->getHeight());
    }
}