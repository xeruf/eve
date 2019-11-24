#include "vector.h"

Vector::Vector(double a, double l) : angle{(l < 0) ? M_PI + a : a}, length{fabs(l)} {}
Vector::Vector(Point p) : Vector(atan(p.y / p.x), ORIGIN / p) {}
Vector::Vector(int a, double l) : Vector(Angle::toRadians(a), l) {}

Vector & Vector::operator = (const Point & p) {
    * this = Vector(p);
    return * this;
}

bool Vector::operator == (const Vector & v) const {
    return coarseEquals(angle.radians(), v.angle.radians()) &&
           coarseEquals(length, v.length);
}
bool Vector::operator == (const Point & p) const {return * this == Vector(p);}

bool Vector::operator != (const Vector & v) const {return !(* this == v);}
bool Vector::operator != (const Point & p) const {return !(* this == Vector(p));}

Vector Vector::operator + (const Vector & v) const {return Vector(ORIGIN + * this + v);}

Vector Vector::operator - () const {return Vector (- angle.radians(), length);}
Vector Vector::operator - (const Vector & v) const {return * this + -v;}
