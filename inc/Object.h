#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <SDL2/SDL.h>

class Object {
    private:
        int32_t width = 50;
        int32_t height = 50;
        SDL_Point position = { 50, 50 };

    public:
        Object ();

        explicit Object (SDL_Point position, int32_t width, int32_t height);

        ~Object ();

        SDL_Point getPosition () const;

        void setPosition (int32_t x, int32_t y);

        void setPosition (SDL_Point position);

        int32_t getWidth () const;

        int32_t getHeight () const;

        void setWidth (int32_t width);
        
        void setHeight (int32_t height);

        bool collidesWithRect (SDL_Point position, int32_t width, int32_t height);

        virtual void draw (SDL_Renderer *renderer, SDL_Point gVPosition, int32_t gVWidth, int32_t gVHeight);
};

#endif