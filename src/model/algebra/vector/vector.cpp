#include "vector.h"

Vector::Vector(const Angle & a, double l) :
    Vector(a.radians(), l) {}

Vector::Vector(double a, double l) :
    angle{(l < 0) ? M_PI + a : a}, length{fabs(l)} {}

Vector::Vector(int a, double l) :
    Vector(Angle::toRadians(a), l) {}

Vector::Vector(Point p) :
    Vector(atan(fabs((p.x == 0) ? 0 : p.y / p.x)), ORIGIN.distanceTo(p)) {}


Vector & Vector::operator = (const Point & p) {
    * this = Vector(p);
    return * this;
}

Vector & Vector::operator += (const Angle & a) {
    this->angle += a;
    return * this;
}
Vector & Vector::operator += (const Vector & v) {return * this = * this + v;}
Vector & Vector::operator -= (const Angle & a) {
    this->angle -= a;
    return * this;
}
Vector & Vector::operator -= (const Vector & v) {return * this = * this - v;}

Vector & Vector::operator += (const Angle & a) {
    this->angle += a;
    return * this;
}
Vector & Vector::operator += (const Vector & v) {return * this = * this + v;}
Vector & Vector::operator -= (const Angle & a) {
    this->angle -= a;
    return * this;
}
Vector & Vector::operator -= (const Vector & v) {return * this = * this - v;}

bool   Vector::operator == (const Angle & a)  const {return a == * this;}
bool   Vector::operator == (const Vector & v) const {
    return coarseEquals(angle.radians(), v.angle.radians()) &&
           coarseEquals(length, v.length);
}
bool   Vector::operator == (const Point & p)  const {return * this == Vector(p);}

bool   Vector::operator != (const Angle & a)  const {return a != * this;}
bool   Vector::operator != (const Vector & v) const {return !(* this == v);}
bool   Vector::operator != (const Point & p)  const {return !(* this == Vector(p));}

Vector Vector::operator +  (const Angle & a)  const {return Vector(a + angle, length);}
Vector Vector::operator +  (const Vector & v) const {return Vector(ORIGIN + * this + v);}


Vector Vector::operator -  (const Angle & a)  const {return Vector(angle - a.radians(), length);}
Vector Vector::operator -  (const Vector & v) const {return * this + -v;}

Vector Vector::operator -  () const {return Vector (angle + M_PI, length);}
