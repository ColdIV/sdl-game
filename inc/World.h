#ifndef _WORLD_H_
#define _WORLD_H_

#include <SDL2/SDL.h>
#include "Player.h"
#include "Level.h"

class World {
    private:
        int32_t width = 1000;
        int32_t height = 500;
        SDL_Point position = { 0, 0 };

        Level level = Level ();
        int32_t tileSize = 10;

    public:
        Player player = Player ();
        
        World ();
        
        World (SDL_Point position, int32_t width, int32_t height);

        ~World ();

        SDL_Point getPosition ();

        int32_t getWidth ();

        int32_t getHeight ();
};

#endif