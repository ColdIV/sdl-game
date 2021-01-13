#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>
#include "World.h"
#include "Timer.h"

class Game {
    private:
        // Constants
        const int FRAMES_PER_SECOND = 60;

        // SDL
        SDL_Window *window = NULL;
		SDL_Renderer *renderer = NULL;
        SDL_Event event;

        // Game attributes
        bool running = false;
		char *title = (char*)"Title";
		int32_t width = 640;
		int32_t height = 480;

        World world = World ();
        Timer fpsTimer = Timer ();
    public:
        Game ();

        Game (char *title, int32_t width, int32_t height);

        ~Game ();

        void createWindow ();

        void clear ();

        void render ();

        void start ();

        void quit ();

        void init ();
		
		void update ();
		
		void draw ();
};

#endif