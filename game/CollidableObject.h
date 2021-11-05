#ifndef _COLLIDABLEOBJECT_H_
#define _COLLIDABLEOBJECT_H_

#include "Object.h"

class CollidableObject : virtual public Object {
    public:
        CollidableObject ();

        CollidableObject (const Object &object);

        bool collidesWithRect (SDL_Point position, int32_t width, int32_t height);
};

#endif