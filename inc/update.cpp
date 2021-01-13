#include "Game.h"
#include <iostream>
void Game::update () {
    SDL_Point move = { 0, 0 };
    int32_t speed = this->world.player.getSpeed();
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_W]) {
        move.y += -1 * speed;
    }
    if (keystates[SDL_SCANCODE_A]) {
        move.x += -1 * speed;
    }
    if (keystates[SDL_SCANCODE_S]) {
        move.y += 1 * speed;
    }
    if (keystates[SDL_SCANCODE_D]) {
        move.x += 1 * speed;
    }

    // Move according to pressed buttons
    this->world.player.move(move.x, move.y);

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