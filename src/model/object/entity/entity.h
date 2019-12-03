#ifndef EVE_ENTITY_H
#define EVE_ENTITY_H

#include "../../../config.h"
#include "../object.h"
#include "../../algebra/algebra.h"

#include <stdexcept>
#include <cmath>
#include <functional>

/** Child of Object. Base for all movable objects in the world */
class Entity : public Object {
private:
    double energy;

    Vector speed = Vector (0.0, 0.0);

    void checkEnergy() const;

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

    /** Multiply this Entity's energy value by the given multipliert */
    double updateEnergy (double multiplier);

    /** Add the given amount of energy to this Entity's internal enery level */
    double addEnergy (double energy);
};


#endif //EVE_ENTITY_H
