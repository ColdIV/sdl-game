#include "Game.h"

void Game::init () {
    // Runs at start of game
    this->world = World ({0, 0}, this->width, this->height);
}