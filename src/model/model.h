#ifndef EVE_MODEL_H
#define EVE_MODEL_H

#include <cmath>

struct Point {
    int x;
    int y;
    Point(int x, int y);
};

bool operator == (const Point &, const Point &);
double operator / (const Point &, const Point &);
Point operator - (const Point &, const Point &);
Point operator + (const Point &, const Point &);

#endif //EVE_MODEL_H
