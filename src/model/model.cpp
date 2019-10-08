//
// Created by aaron on 07/10/2019.
//

#include "model.h"

Point::Point(int x, int y) : x{x}, y{y} {}

bool operator == (Point & a, Point & b) {
    return a.x == b.x && a.y == b.y;
}

