#ifndef EVE_ENTITY_H
#define EVE_ENTITY_H

#include "../object.h"
#include "../../algebra/algebra.h"

#include <stdexcept>
#include <cmath>

class Entity : public Object {
private:
    double energy;

    Vector speed = Vector (0.0, 0.0);

    void checkEnergy() const;

    void setPosition(Point position);
    void setPosition(double x, double y);

public:
    Entity(double x, double y, double energy);
    Entity(Point position, double energy);
    ~Entity() override = 0;

    [[nodiscard]] double getEnergy() const ;
    [[nodiscard]] double getRadius() const ;

    const Vector & applyForce (const Vector & v);
    const Vector & applyFriction ();

    Point updatePosition ();
};


#endif //EVE_ENTITY_H
