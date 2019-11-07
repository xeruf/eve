#ifndef EVE_MODEL_H
#define EVE_MODEL_H

#include <cmath>

struct Point;
struct Vector;

struct Point {
    double x;
    double y;
    Point (double x, double y);

    bool operator == (const Point & p) const;

    double operator / (const Point & p) const;

    Point operator + (const Point & p) const;
    Point operator + (const Vector & v) const;

    Point operator - (const Point & p) const;
    Point operator - (const Vector & v) const;

    Vector operator >> (const Point & p) const;
    Vector operator << (const Point & p) const;
};

struct Vector {
    double angle;
    double length;

    explicit Vector (Point p);
    Vector (double angle, double length);
    Vector (int angle, double length);

    bool operator == (const Vector & v) const;

    Vector operator + (const Vector & v) const;

    Vector operator - (const Vector & v) const;
};

static const Point ORIGIN = Point(0, 0);

#endif //EVE_MODEL_H
