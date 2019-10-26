#ifndef EVE_ENTITY_H
#define EVE_ENTITY_H

#include "../object.h"

#include <stdexcept>

class Entity : public Object {
private:
    void setPosition(Point position);
    void setPosition(double x, double y);

protected:
    double energy;

    void checkEnergy();

public:
    Entity(double x, double y, double energy);
    ~Entity() override = 0;

    double getEnergy();
};


#endif //EVE_ENTITY_H
