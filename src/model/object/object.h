//
// Created by aaron on 26/09/2019.
//

/* Abstract base class for all objects in the world */

#ifndef EVE_OBJECT_H
#define EVE_OBJECT_H


#include "../../geometry/0d/point.h"

class Object {
protected:
    Point position;
public:
    explicit Object(Point);
    Object(int, int);

    virtual ~Object() = 0;

    virtual Point getPosition();
    virtual void setPosition(Point);
    virtual void setPosition(int, int);
};

#endif //EVE_OBJECT_H
