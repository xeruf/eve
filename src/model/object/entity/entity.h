#ifndef EVE_ENTITY_H
#define EVE_ENTITY_H

#include "../object.h"

#include <stdexcept>
#include <cmath>

class Entity : public Object {
private:
    double energy;

    void checkEnergy() const ;

    void setPosition(Point position);
    void setPosition(double x, double y);

public:
    Entity(double x, double y, double energy);
    Entity(Point position, double energy);
    ~Entity() override = 0;

    [[nodiscard]] double getEnergy() const ;
    [[nodiscard]] double getRadius() const ;
};


#endif //EVE_ENTITY_H
