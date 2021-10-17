#ifndef _MOVEABLEOBJECT_H_
#define _MOVEABLEOBJECT_H_

#include <cmath>
#include "Object.h"
#include "CollidableObject.h"

class MoveableObject : virtual public Object {
    private:
        int32_t speed = 5;
        float angle = 0;
        float turnSpeed = 0.05;

    public:
        int32_t getSpeed ();

        float getAngle ();

        float getTurnSpeed ();

        void setSpeed (int32_t speed);

        void setAngle (float angle);

        void setTurnSpeed (float turnSpeed);

        void turn (int32_t direction);

        SDL_Point move (int32_t direction);

        bool collides (CollidableObject obj);

        bool collides (MoveableObject obj);

        void draw (SDL_Renderer *renderer, SDL_Point gVPosition, int32_t gVWidth, int32_t gVHeight);
};

#endif