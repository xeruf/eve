//
// Created by janek on 17.09.19.
//

#ifndef EVE_FOOD_H
#define EVE_FOOD_H

#include "../entity.h"
#include "../../../../geometry/0d/point.h"

#include <exception>

#include <experimental/random>
#include <iostream>

class Food : public Entity {
private:
    int value;

    void checkValue();
public:

    int getValue();
};
#endif //EVE_FOOD_H
