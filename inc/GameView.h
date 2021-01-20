#ifndef _GAMEVIEW_H_
#define _GAMEVIEW_H_

#include <SDL2/SDL.h>

class GameView {
    private:
        int32_t width;
        int32_t height;
        SDL_Point position;

        int32_t paddingX = 50;
        int32_t paddingY = 50;
        bool playerCentered = false;

    public:
        GameView ();
        
        GameView (SDL_Point position, int32_t width, int32_t height);

        ~GameView ();

        SDL_Point getPosition ();

        int32_t getWidth ();

        int32_t getHeight ();

        void centerPlayer (bool value);

        bool isPlayerCentered ();

        void move (SDL_Point position, int32_t width, int32_t height);
};

#endif