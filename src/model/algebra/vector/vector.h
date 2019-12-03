#ifndef EVE_VECTOR_H
#define EVE_VECTOR_H

#include "../algebra_conf.h"
#include "../angle/angle.h"
#include "../point/point.h"

#include <cmath>

/** A mathematical Vector in polar notation, represented with an Angle and a length */
struct Vector {
    Angle angle;
    double length;

    /** Constructs a Vector with the Angle and length given */
    Vector (const Angle & angle, double length);

    /** Constructs a Vector with the angle and length given
     * @param angle given in radians */
    Vector (double angle, double length);

    /** Constructs a Vector with the angle and length given
     * @param angle given in degrees */
    Vector (int angle, double length);

    /** Constructs a Vector from Origin (0, 0) to the Point given */
    explicit Vector (Point p);

    /** Stores the Point given as Vector */
    Vector & operator = (const Point & p);

    /** Adds the Angle given to this Vector */
    Vector & operator += (const Angle & a);
    /** Adds the Vector given to this Vector */
    Vector & operator += (const Vector & v);

    /** Subtracts the Angle given to this Vector */
    Vector & operator -= (const Angle & a);
    /** Subtracts the Vector given to this Vector */
    Vector & operator -= (const Vector & v);

    /** Compares the internal Angle with the Angle given */
    bool operator == (const Angle & a) const;
    /** Checks if both Vectors given are the same */
    bool operator == (const Vector & v) const;
    /** Checks whether this Vector from Origin points to the Point given */
    bool operator == (const Point & p) const;

    /** Compares the internal Angle with the Angle given */
    bool operator != (const Angle & a) const;
    /** Checks if both Vectors differ in either direction or length */
    bool operator != (const Vector & v) const;
    /** Checks whether this Vector from Origin does not point to the Point given */
    bool operator != (const Point & p) const;

    /** Returns a Vector with the Angle given added to this Vector's internal one */
    Vector operator + (const Angle & a) const;
    /** Returns a Vector as sum of the two Vectors given */
    Vector operator + (const Vector & v) const;

    /** Returns the sum of the two Vectors given */
    Vector operator - (const Angle & a) const;
    /** Returns the difference between the two Vectors given */
    Vector operator - (const Vector & v) const;

    /** Returns a Vector with same length but reversed direction */
    Vector operator - () const;
};

#endif //EVE_VECTOR_H
