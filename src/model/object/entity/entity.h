#ifndef EVE_ENTITY_H
#define EVE_ENTITY_H

#include "../object.h"
#include "../../algebra/algebra.h"

#include <stdexcept>
#include <cmath>
#include <functional>

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

    /** Returns the internal energy value */
    [[nodiscard]] double getEnergy() const ;
    /** Returns the radius of this Entity which is based on its energy value */
    [[nodiscard]] double getRadius() const ;

    /** Adds the given Vector as force to this Entity, changing its speed */
    const Vector & applyForce (const Vector & v);
     /** Applys friction as a force to this Entity, slowing its speed */
    const Vector & applyFriction ();

    /** Updates this Entity's position based on its speed */
    Point updatePosition ();
    /** Updates this Entity's position based on its speed and normalises this position using the function given */
    Point updatePosition (const std::function<Point(Point)> & normalise);
};


#endif //EVE_ENTITY_H
