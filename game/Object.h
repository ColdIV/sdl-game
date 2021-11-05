#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Object {
    private:
        int32_t width = 50;
        int32_t height = 50;
        const char* imagePath = "textures/default.png";
        SDL_Point position = { 50, 50 };
        SDL_Texture *texture = nullptr;

    public:
        Object ();

        Object (SDL_Point position, int32_t width, int32_t height);

        ~Object ();

        SDL_Point getPosition () const;

        void setPosition (int32_t x, int32_t y);

        void setPosition (SDL_Point position);

        int32_t getWidth () const;

        int32_t getHeight () const;

        SDL_Texture* getTexture () const;

        void setWidth (int32_t width);
        
        void setHeight (int32_t height);

        void setImagePath (const char* path);

        void loadTexture (SDL_Renderer *renderer);

        void draw (SDL_Renderer *renderer, SDL_Point gVPosition, int32_t gVWidth, int32_t gVHeight);
};

#endif