#ifndef EVE_MODEL_H
#define EVE_MODEL_H

#include <cmath>

struct Point {
    int x;
    int y;
    Point(int x, int y);

    bool operator == (const Point &);
    double operator / (const Point & a);
    Point operator - (const Point & a);
    Point operator + (const Point & a);
};

#endif //EVE_MODEL_H
