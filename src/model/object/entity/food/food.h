//
// Created by janek on 17.09.19.
//

#ifndef EVE_FOOD_H
#define EVE_FOOD_H

#include "../entity.h"

#include <iostream>
#include <stdexcept>

class Food : public Entity {
public:
    Food(Point position, int value);
    Food(int x, int y, int value);
};

#endif //EVE_FOOD_H
