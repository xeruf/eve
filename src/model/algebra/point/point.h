#ifndef EVE_POINT_H
#define EVE_POINT_H

#include "../algebra_conf.h"

#include <cmath>
#include <iostream>

/** A Point on a cartesian grid, represented with an x- and y-coordinate (x|y) */
struct Point {
    double x;
    double y;

    /** Constructs a Point (x|y) with the coordinates given */
    Point (double x, double y);
    /** Constructs the Point the given Vector is pointing to from Origin */
    explicit Point (const Vector & v);

    /** Returns the distance between the two Points given */
    [[nodiscard]] double distanceTo (const Point & p) const;

    /** Returns the Vector from this Point to the one given */
    [[nodiscard]] Vector vectorTo (const Point & p) const;

    /** Checks whether this Point lies within the cone given
     * @param apex is the peak of the cone, where the angle is located in
     * @param centre is the Vector from the apex through the middle of the cone
     * @param angle is the overall angle of the cone */
    [[nodiscard]] bool withinCone (const Point & apex, const Vector & centre, const Angle & angle) const;

    /** Returns the Point the given Vector is pointing to from Origin */
    Point & operator = (const Vector & v);

    /** Adds the Vector given onto this Point */
    Point & operator += (const Vector & v);

    /** Compares the two Points given */
    bool operator == (const Point & p) const;
    /** Checks whether the Vector from Origin points to this Point */
    bool operator == (const Vector & v) const;

    /** Checks whether the two Points given differ from each other */
    bool operator != (const Point & p) const;
    /** Checks if the given Vector from Origin does not point to this Point */
    bool operator != (const Vector & v) const;

    /** Returns the sum of both x and y from both Points given */
    Point operator + (const Point & p) const;
    /** Returns the Point the given Vector is pointing to from this Point on */
    Point operator + (const Vector & v) const;

    /** Returns the difference of both x and y from both Points given */
    Point operator - (const Point & p) const;
    /** Returns the Point the given Vector inverted is pointing to from this Point on */
    Point operator - (const Vector & v) const;
};

/** Origin of the coordinate system, Point (0|0). Used for Vector calculations. */
static const Point ORIGIN = Point (0, 0);

#endif //EVE_POINT_H
