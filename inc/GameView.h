#ifndef _GAMEVIEW_H_
#define _GAMEVIEW_H_

#include <SDL2/SDL.h>

class GameView {
    private:
        int32_t width;
        int32_t height;
        SDL_Point position;

    public:
        GameView ();
        
        GameView (SDL_Point position, int32_t width, int32_t height);

        ~GameView ();

        SDL_Point getPosition ();

        int32_t getWidth ();

        int32_t getHeight ();
};

#endif