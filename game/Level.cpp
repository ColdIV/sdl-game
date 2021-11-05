#include "Level.h"

Level::Level () {
    this->load();
}

Level::Level (int32_t tileSize) {
    this->tileSize = tileSize;
    this->load();
}

Level::~Level () {}

int Level::getLevel () {
    return this->index;
}

void Level::setLevel (int index) {
    this->index = index;
}

void Level::save () { 
    std::string path = this->filepath + std::to_string(this->index) + this->filetype;
    const char* cpath = &path[0];

    std::ofstream File (cpath);
    for (unsigned y = 0; y < this->_Y; ++y) {
        for (unsigned x = 0; x < this->_X; ++x) {
            File << this->data[x][y] << " "; 
        }
    }
}

void Level::load () {
    std::string path = this->filepath + std::to_string(this->index) + this->filetype;
    const char* cpath = &path[0];

    std::ifstream File (cpath);
    for (unsigned y = 0; y < this->_Y; ++y) {
        for (unsigned x = 0; x < this->_X; ++x) {
            File >> this->data[x][y];
        }
    }
}

std::vector <Object> Level::getTilesOfType(int type) {
    std::vector <Object> tiles;
    int32_t w, h;
    SDL_Point p;
    w = this->tileSize;
    h = this->tileSize;

    for (int y = 0; y < this->_Y; ++y) {
        for (int x = 0; x < this->_X; ++x) {
            if (this->data[x][y] == type) {
                p = { x * this->tileSize, y * this->tileSize };
                Object o = Object (p, w, h);
                tiles.push_back(o);
            }
        }
    }

    return tiles;
}

void Level::draw (SDL_Renderer *renderer, SDL_Point gVPosition, int32_t gVWidth, int32_t gVHeight) {
    int32_t w, h;
    SDL_Point p;
    SDL_Rect tile_r;
    w = this->tileSize;
    h = this->tileSize;

    for (int y = 0; y < this->_Y; ++y) {
        for (int x = 0; x < this->_X; ++x) {
            if (this->data[x][y] == 1) {
                p = { x * this->tileSize, y * this->tileSize };

                // Skip if not visible
                if (!(p.x + w > gVPosition.x && p.x < gVPosition.x + gVWidth)) {
                    continue;
                }

                // Translate according to gameView
                p.x -= gVPosition.x;
                p.y -= gVPosition.y;

                tile_r.x = p.x;
                tile_r.y = p.y;
                tile_r.w = w;
                tile_r.h = h;

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &tile_r);
            }
        }
    }
}

// For testing only
void Level::printToConsole () {
    std::cout << "Level " << this->index << "\n";
    for (int y = 0; y < this->_Y; ++y) {
        for (int x = 0; x < this->_X; ++x) {
            std::cout << this->data[x][y];
        }
        std::cout << "\n";
    }
}

void Level::getExampleLevel () {
    for (int x = 0; x < this->_X; ++x) {
        for (int y = 0; y < this->_Y; ++y) {
            this->data[x][y] = 0;

            if (1 + y == this->_Y) {
                this->data[x][y] = 1;
            }
        }
    }

    this->save();
}