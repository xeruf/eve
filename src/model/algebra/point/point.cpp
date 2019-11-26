#include "../vector/vector.h"

Point::Point (double x, double y) :
    x{x}, y{y} {}

Point::Point (const Vector & v) :
    x{(ORIGIN + v).x}, y{(ORIGIN + v).y} {}


double Point::distanceTo (const Point & p) const {
    return sqrt(pow(p.x - x, 2.0) + pow(p.y - y, 2.0));
}


Point & Point::operator = (const Vector & v) {
    * this = ORIGIN + v;
    return * this;
}

bool Point::operator == (const Point & p) const {
    return coarseEquals(x, p.x) && coarseEquals(y, p.y);
}
bool Point::operator == (const Vector & v) const {
    return v == * this;
}

bool Point::operator != (const Point & p) const {
    return !(p == * this);
}
bool Point::operator != (const Vector & v) const {
    return v != * this;
}

Point Point::operator + (const Point & p) const {
    return Point(x + p.x, y + p.y);
}
Point Point::operator + (const Vector & v) const {
    return Point(x + v.length * cos(v.angle.radians()), y + v.length * sin(v.angle.radians()));
}

Point Point::operator - (const Point & p) const {
    return Point(x - p.x, y - p.y);
}
Point Point::operator - (const Vector & v) const {
    return * this + -v;
}

Vector Point::operator >= (const Point & p) const {
    const Point q(* this - p);
    double angle = atan (q.y / q.x);
    if (p.x < 0 && p.y < 0) angle += M_PI;
    return Vector(angle, ORIGIN.distanceTo(q));
}
Vector Point::operator <= (const Point & p) const {
    return p >= * this;
}

bool Point::withinCone (const Point & apex, const Vector & centre, const Angle & angle) const {
    Vector v = apex >= * this;
    double enclosedAngle = v.angle.angleTo(centre.angle);

    return (v.length <= centre.length && enclosedAngle <= 0.5 * angle.radians());
}