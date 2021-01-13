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