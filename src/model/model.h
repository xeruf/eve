#ifndef EVE_MODEL_H
#define EVE_MODEL_H

#include <cmath>

struct Point {
    double x;
    double y;
    Point(double x, double y);

    bool operator == (const Point &);
    double operator / (const Point & a);
    Point operator - (const Point & a);
    Point operator + (const Point & a);
};

#endif //EVE_MODEL_H
