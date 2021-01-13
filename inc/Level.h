#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <SDL2/SDL.h>
#include <fstream>
#include <string>
#include <iostream>

class Level {
    private:
        const static int _X = 10;
        const static int _Y = 5;
        int data[_X][_Y];
        std::string filepath = "levels/level-";
        std::string filetype = ".txt";
        int index = 1;

    public:
        Level ();

        ~Level ();

        void save ();

        void load ();

        void draw (SDL_Renderer *renderer, int32_t tileSize, SDL_Point gVPosition, int32_t gVWidth, int32_t gVHeight);

        // For testing only
        void printToConsole ();
        void getExampleLevel ();
};

#endif