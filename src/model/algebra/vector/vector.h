#ifndef EVE_VECTOR_H
#define EVE_VECTOR_H

#include "../algebra_conf.h"
#include "../angle/angle.h"
#include "../point/point.h"

#include <cmath>

struct Vector {
    Angle angle;
    double length;

    Vector (double angle, double length);
    Vector (int angle, double length);
    explicit Vector (Point p);

    Vector & operator = (const Point & p);

    bool operator == (const Vector & v) const;
    bool operator == (const Point & p) const;

    bool operator != (const Vector & v) const;
    bool operator != (const Point & p) const;

    Vector operator + (const Vector & v) const;

    Vector operator - () const;
    Vector operator - (const Vector & v) const;
};

#endif //EVE_VECTOR_H
