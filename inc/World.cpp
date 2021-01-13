#include "World.h"

World::World () {
    this->level.printToConsole(); // @TODO: Remove / testing
}
        
World::World (SDL_Point position, int32_t width, int32_t height) {
    this->gameView = GameView (position, width, height);
}

World::~World () {}

int32_t World::getWidth () {
    return this->width;
}

int32_t World::getHeight () {
    return this->height;
}

void World::update () {
    SDL_Point move = { 0, 0 };
    int32_t speed = this->player.getSpeed();
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
    this->player.move(move.x, move.y);

    // Update gameView position
    this->gameView.move(this->player.getPosition(), this->player.getWidth(), this->player.getHeight());
}

void World::draw (SDL_Renderer *renderer) {
    int32_t w, h;
	SDL_Point p;

    SDL_Rect gameView_r;
    p = this->gameView.getPosition();
    w = this->gameView.getWidth();
    h = this->gameView.getHeight();
    gameView_r.x = p.x;
    gameView_r.y = p.y;
    gameView_r.w = w;
    gameView_r.h = h;

    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderDrawRect(renderer, &gameView_r);

    this->level.draw(renderer, this->tileSize);
    this->player.draw(renderer);
}