#include "World.h"

World::World () {}
        
World::World (SDL_Point position, int32_t width, int32_t height) {
    this->gameView = GameView (position, width, height);
    this->gameView.centerPlayer(true);
    this->level = Level (this->tileSize);
    this->loadObstacles();
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
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_W]) {
        move.y = 1;
    }
    if (keystates[SDL_SCANCODE_A]) {
        move.x = -1;
    }
    if (keystates[SDL_SCANCODE_S]) {
        move.y = -1;
    }
    if (keystates[SDL_SCANCODE_D]) {
        move.x = 1;
    }

    SDL_Point oldPosition = this->player.getPosition();
    this->player.turn(move.x);
    SDL_Point newPosition = this->player.move(move.y);

    // Check collision
    int32_t width = this->player.getWidth();
    int32_t height = this->player.getHeight();
    bool checkX = true, checkY = true;
    for (CollidableObject co : this->obstacles) {
        // Collision on X movement
        if (co.collidesWithRect({newPosition.x, oldPosition.y}, width, height)) {
            checkX = false;
        }

        // Collision on Y movement
        if (co.collidesWithRect({oldPosition.x, newPosition.y}, width, height)) {
            checkY = false;
        }

        // If both collide, break out of loop
        if (checkX == false && checkY == false) {
            break;
        }
    }

    if (move.y != 0 && checkX && checkY) {
        this->player.setPosition(newPosition);
    }

    // Update gameView position
    this->gameView.move(this->player.getPosition(), this->player.getWidth(), this->player.getHeight());
}

void World::draw (SDL_Renderer *renderer) {
    int32_t w, h;
	SDL_Point p;

    p = this->gameView.getPosition();
    w = this->gameView.getWidth();
    h = this->gameView.getHeight();

    this->level.draw(renderer, p, w, h);
    this->player.draw(renderer, p, w, h);
}

void World::loadObstacles () {
    std::vector <CollidableObject> objects;
    
    std::vector <Object> walls = this->level.getTilesOfType(1);
    std::vector <Object> blocks = this->level.getTilesOfType(2);

    for (Object o : walls) {
        CollidableObject co = CollidableObject(o);
        objects.push_back(co);
    }

    for (Object o : blocks) {
        CollidableObject co = CollidableObject(o);
        objects.push_back(co);
    }

    this->obstacles = objects;
}

void World::loadLevel (int index) {
    this->level.setLevel(index);
    this->level.load();
    this->loadObstacles();
}

void World::nextLevel () {
    int currentLevel = this->level.getLevel();
    this->loadLevel(currentLevel + 1);
}

void World::setLevel (int index) {
    this->loadLevel(index);
}