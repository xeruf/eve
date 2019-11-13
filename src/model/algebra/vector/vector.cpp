#include "vector.h"

Vector::Vector(double a, double l) : angle{(a < 0) ? a + M_PI : a}, length{fabs(l)} {}
Vector::Vector(Point p) : Vector(atan(p.y / p.x), ORIGIN / p) {}
Vector::Vector(int a, double l) : Vector(Angle::toRadians(a), l) {}

Vector & Vector::operator = (const Point & p) {
    * this = Vector(p);
    return * this;
}

bool Vector::operator == (const Vector & v) const {
    return compare(angle.radians(), v.angle.radians()) &&
        compare(length, v.length);
}
bool Vector::operator == (const Point & p) const {return * this == Vector(p);}

Vector Vector::operator + (const Vector & v) const {return Vector(ORIGIN + * this + v);}

Vector Vector::operator - () const {return Vector(ORIGIN - * this);}
Vector Vector::operator - (const Vector & v) const {return * this + -v;}
