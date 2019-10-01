//
// Created by aaron on 26/09/2019.
//

/* Abstract base class for all objects in the world */

#ifndef EVE_ENTITY_H
#define EVE_ENTITY_H

#include "../../model.h"
#include "../object.h"

class Entity : public Object {
protected:
    Point position;
public:
    explicit Entity(Point position);
    Entity(int x, int y);

    virtual ~Entity() = 0;

    virtual Point getPosition();
    virtual void setPosition(Point position);
    virtual void setPosition(int x, int y);
};

#endif //EVE_ENTITY_H
