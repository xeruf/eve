//
// Created by janek on 17.09.19.
//

#ifndef EVE_FOOD_H
#define EVE_FOOD_H

#include "../entity.h"

#include <exception>

#include <experimental/random>
#include <iostream>

class Food : public Entity {
private:
    int value;

    void checkValue();
public:
    Food();
    Food(Point position, int value);
    Food(int x, int y, int value);
    ~Food() override;

    int getValue();
};
#endif //EVE_FOOD_H
