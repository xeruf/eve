#ifndef EVE_FOOD_H
#define EVE_FOOD_H

#include "../entity.h"

#include <iostream>
#include <stdexcept>

class Food : public Entity {
public:
    Food(Point position, double value);
    Food(double x, double y, double value);
};

#endif //EVE_FOOD_H
