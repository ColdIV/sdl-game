#include "Level.h"

Level::Level () {}

Level::~Level () {}

void Level::save () {
    std::ofstream File (this->filename);
    for (unsigned y = 0; y < this->_Y; ++y) {
        for (unsigned x = 0; x < this->_X; ++x) {
            File << this->data[x][y] << " "; 
        }
    }
}

void Level::load () {
    std::ifstream File (this->filename);
    for (unsigned y = 0; y < this->_Y; ++y) {
        for (unsigned x = 0; x < this->_X; ++x) {
            File >> this->data[x][y];
        }
    }
}