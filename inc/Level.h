#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <SDL2/SDL.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Object.h"

class Level {
    private:
        const static int _X = 20;
        const static int _Y = 10;
        int data[_X][_Y];
        std::string filepath = "levels/level-";
        std::string filetype = ".txt";
        int index = 1;
        int32_t tileSize = 50;

    public:
        Level ();

        Level (int32_t tileSize);

        ~Level ();

        int getLevel ();

        void setLevel (int index);

        void save ();

        void load ();

        void draw (SDL_Renderer *renderer, SDL_Point gVPosition, int32_t gVWidth, int32_t gVHeight);

        std::vector <Object> getTilesOfType(int type);

        // For testing only
        void printToConsole ();
        void getExampleLevel ();
};

#endif