//
// Created by aaron on 26/09/2019.
//

/* Abstract base class for all objects in the world */

#ifndef EVE_OBJECT_H
#define EVE_OBJECT_H

#include "../model.h"

class Object {
protected:
    Point position;

public:
    explicit Object(Point position);
    Object(int x, int y);

    virtual ~Object() = 0;
};

#endif //EVE_OBJECT_H
