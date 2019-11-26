#ifndef EVE_POINT_H
#define EVE_POINT_H

#include "../algebra_conf.h"

#include <cmath>
#include <iostream>

struct Point {
    double x;
    double y;
    Point (double x, double y);
    explicit Point (const Vector & v);

    [[nodiscard]] double distanceTo (const Point & p) const;
    [[nodiscard]] Vector vectorTo (const Point & p) const;

    Point & operator = (const Vector & v);

    bool operator == (const Point & p) const;
    bool operator == (const Vector & v) const;

    bool operator != (const Point & p) const;
    bool operator != (const Vector & v) const;

    Point operator + (const Point & p) const;
    Point operator + (const Vector & v) const;

    Point operator - (const Point & p) const;
    Point operator - (const Vector & v) const;

    [[nodiscard]] bool withinCone(const Point & apex, const Vector & centre, const Angle & angle) const;
};

static const Point ORIGIN = Point(0, 0);

#endif //EVE_POINT_H
