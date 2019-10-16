//
// Created by aaron on 01/10/2019.
//

#ifndef EVE_OBJECT_H
#define EVE_OBJECT_H

#include "../model.h"

#include <vector>

/* Abstract base class for all objects in the world */
class Object {
protected:
    Point position;

public:
    Object(int x, int y);
    virtual ~Object() = 0;

    Point getPosition();
};


#endif //EVE_OBJECT_H
