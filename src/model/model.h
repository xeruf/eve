#ifndef EVE_MODEL_H
#define EVE_MODEL_H

#include <cmath>

struct Point {
    double x;
    double y;
    Point(double x, double y);
};

bool operator == (const Point &, const Point &);
double operator / (const Point &, const Point &);
Point operator - (const Point &, const Point &);
Point operator + (const Point &, const Point &);

#endif //EVE_MODEL_H
