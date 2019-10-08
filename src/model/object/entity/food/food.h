//
// Created by janek on 17.09.19.
//

#ifndef EVE_FOOD_H
#define EVE_FOOD_H

#include "../entity.h"

#include <iostream>
#include <exception>

class Food : public Entity {
private:
    int value;

    void checkValue();
public:
    Food(Point position, int value);
    Food(int x, int y, int value);

    int getValue();
};
#endif //EVE_FOOD_H
