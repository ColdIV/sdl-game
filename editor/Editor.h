#ifndef _EDITOR_H_
#define _EDITOR_H_

#include <SDL2/SDL.h>
#include "Timer.h"

class Editor {
    private:
        // Constants
        const int FRAMES_PER_SECOND = 60;

        // SDL
        SDL_Window *window = NULL;
		SDL_Renderer *renderer = NULL;
        SDL_Texture *texture = NULL;
        SDL_Event event;

        // Editor attributes
        bool running = false;
		char *title = (char*)"Editor";
		int32_t width = 640;
		int32_t height = 480;

        Timer fpsTimer = Timer ();
    public:
        Editor ();

        Editor (char *title, int32_t width, int32_t height);

        ~Editor ();

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