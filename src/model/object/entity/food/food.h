#ifndef EVE_FOOD_H
#define EVE_FOOD_H

#include "../entity.h"

#include <iostream>
#include <stdexcept>

/** Subclass of Entity representing all Food items */
class Food : public Entity {
public:
    /** Constructs an object with the given x- and y-coordinate */
    Food(Point position, double value);
    /** Constructs an object with the given position */
    Food(double x, double y, double value);
};

#endif //EVE_FOOD_H
