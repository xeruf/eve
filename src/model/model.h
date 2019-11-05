#ifndef EVE_MODEL_H
#define EVE_MODEL_H

#include <cmath>

struct Point {
    double x;
    double y;
    Point(double x, double y);

    bool operator == (const Point & p) const;
    double operator / (const Point & p);
    Point operator - (const Point & p);
    Point operator + (const Point & p);
};

#endif //EVE_MODEL_H
