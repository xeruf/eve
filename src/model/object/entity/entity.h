//
// Created by aaron on 07/10/2019.
//

#ifndef EVE_ENTITY_H
#define EVE_ENTITY_H

#include "../object.h"
#include <stdexcept>

class Entity : public Object {
protected:
    int energy;

    void checkEnergy();

public:
    Entity(int x, int y, int energy);

    virtual ~Entity() = 0;

    void setPosition(Point position);
    void setPosition(int x, int y);
    int getEnergy();
};


#endif //EVE_ENTITY_H
