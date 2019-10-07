//
// Created by aaron on 07/10/2019.
//

#ifndef EVE_MODEL_H
#define EVE_MODEL_H

#include <exception>

struct Point {
    int x;
    int y;
    Point(int x, int y);
};

bool operator == (Point & a, Point & b);

#endif //EVE_MODEL_H
