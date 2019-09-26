//
// Created by janek on 17.09.19.
//

#ifndef EVE_FOOD_H
#define EVE_FOOD_H

#include "../object.h"

#include <exception>

#include <iostream>

class Food : public Object {
private:
    int value;

    void checkValue();
public:
    Food(Point, int);
    Food(int, int, int);
    ~Food() override;

    int getValue();
};
#endif //EVE_FOOD_H
