#ifndef EVE_ENTITY_H
#define EVE_ENTITY_H

#include "../object.h"

#include <stdexcept>

class Entity : public Object {
private:
    void setPosition(Point position);
    void setPosition(int x, int y);

protected:
    int energy;

    void checkEnergy();

public:
    Entity(int x, int y, int energy);
    ~Entity() override = 0;

    int getEnergy();
};


#endif //EVE_ENTITY_H
