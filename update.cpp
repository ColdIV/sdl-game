#include "Game.h"

void Game::update () {
    // Handle events
    while (SDL_PollEvent(&(this->event))) {
        switch (event.type) {
            case SDL_QUIT:
                this->running = false;
                break;
            case SDL_KEYDOWN:
                // Key press
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    this->running = false;
                }
                break;
            case SDL_KEYUP:
                // Key release
            default:
                break;
        }
    }
}