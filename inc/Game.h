#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>

class Game {
    private:
        // SDL
        SDL_Window *window = NULL;
		SDL_Renderer *renderer = NULL;
        SDL_Event event;

        // Game attributes
        bool running = false;
		const char *title = "Title";
		int32_t width = 640;
		int32_t height = 480;
    public:
        Game ();

        Game (const char *title, int32_t width, int32_t height);

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