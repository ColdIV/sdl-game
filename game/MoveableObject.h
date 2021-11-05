#ifndef _MOVEABLEOBJECT_H_
#define _MOVEABLEOBJECT_H_

#include "Object.h"

class MoveableObject : virtual public Object {
    private:
        int32_t speed = 5;

    public:
        int32_t getSpeed ();

        void setSpeed (int32_t speed);

        void move (int32_t x, int32_t y);

        void move (int32_t w, int32_t a, int32_t s, int32_t d);
};

#endif