//
// Created by aaron on 07/10/2019.
//

#ifndef EVE_ENTITY_H
#define EVE_ENTITY_H

#include "../object.h"

class Entity : public Object {
public:
    Entity(int x, int y);
    explicit Entity(Point position);

    virtual ~Entity() = 0;
};


#endif //EVE_ENTITY_H
