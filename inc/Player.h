#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SDL2/SDL.h>

class Player {
    private:
        int32_t width = 50;
        int32_t height = 100;
        SDL_Point position = { 0, 0 };
        int32_t speed = 5;

    public:
        Player ();

        Player (SDL_Point position, int32_t width, int32_t height);

        ~Player ();

        SDL_Point getPosition ();

        int32_t getWidth ();

        int32_t getHeight ();

        int32_t getSpeed ();

        void move (int32_t x, int32_t y);

        void move (int32_t w, int32_t a, int32_t s, int32_t d);

        void draw (SDL_Renderer *renderer, SDL_Point gVPosition, int32_t gVWidth, int32_t gVHeight);
};

#endif