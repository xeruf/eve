#ifndef EVE_MODEL_H
#define EVE_MODEL_H

#include <cmath>

#define CONST_MODIFIER 1000

struct Point;
struct Vector;

struct Point {
    double x;
    double y;
    Point (double x, double y);

    Point & operator = (const Vector & v);

    bool operator == (const Point & p) const;

    double operator / (const Point & p) const;      // Evaluates the distance between the two points

    Point operator + (const Point & p) const;
    Point operator + (const Vector & v) const;

    Point operator - (const Point & p) const;
    Point operator - (const Vector & v) const;

    /* Operators to calculate the vector between two points */
    Vector operator >= (const Point & p) const;
    Vector operator <= (const Point & p) const;
};

struct Vector {
    double angle;
    double length;

    explicit Vector (Point p);
    Vector (double angle, double length);
    Vector (int angle, double length);

    Vector & operator = (const Point & p);

    bool operator == (const Vector & v) const;
    bool operator == (const Point & p) const;       // Compares 'this' with ORIGIN >> p

    Vector operator + (const Vector & v) const;

    Vector operator - () const;
    Vector operator - (const Vector & v) const;
};

static const Point ORIGIN = Point(0, 0);

#endif //EVE_MODEL_H
