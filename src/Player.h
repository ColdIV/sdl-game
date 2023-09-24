#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Object.h"

class Player : public Object {
    using Object::Object;

    private:
        int32_t speed = 3;

    public:
        int32_t getSpeed ();

        void setSpeed (int32_t speed);

        void move (int32_t x, int32_t y);

        void move (int32_t w, int32_t a, int32_t s, int32_t d);
    
        // Overrides
        void draw (SDL_Renderer *renderer, SDL_Point gVPosition, int32_t gVWidth, int32_t gVHeight) override;
};

#endif