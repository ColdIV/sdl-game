#include "Level.h"

Level::Level () {
    this->load();
}

Level::~Level () {}

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

// For testing only
void Level::printToConsole () {
    std::cout << "Level " << this->index << "\n";
    for (unsigned y = 0; y < this->_Y; ++y) {
        for (unsigned x = 0; x < this->_X; ++x) {
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