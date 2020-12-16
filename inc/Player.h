#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SDL2/SDL.h>

class Player {
    private:
        int32_t width = 50;
        int32_t height = 100;
        SDL_Point position = { 0, 0 };

    public:
        Player ();

        Player (SDL_Point position, int32_t width, int32_t height);

        ~Player ();

        SDL_Point getPosition ();

        int32_t getWidth ();

        int32_t getHeight ();
};

#endif