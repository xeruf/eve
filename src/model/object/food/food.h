//
// Created by janek on 17.09.19.
//

#ifndef EVE_FOOD_H
#define EVE_FOOD_H

#include "../object.h"

class Food : Object {
private:
    int value;
public:
    explicit Food(Point, int);
    explicit Food(int, int, int);

    int getValue();
};
#endif //EVE_FOOD_H
