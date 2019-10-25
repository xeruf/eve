#ifndef EVE_MODEL_H
#define EVE_MODEL_H

#include <cmath>

struct Point {
    int x;
    int y;
    Point(int x, int y);
};

bool operator == (const Point & a, const Point & b);
double operator / (const Point & a, const Point & b);
Point operator - (const Point & a, const Point & b);
Point operator + (const Point & a, const Point & b);

#endif //EVE_MODEL_H
