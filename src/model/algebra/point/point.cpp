#include "../vector/vector.h"

Point::Point(double x, double y) : x{x}, y{y} {}

Point & Point::operator = (const Vector & v) {
    * this = ORIGIN + v;
    return * this;
}

bool Point::operator == (const Point & p) const {return round(CONST_MULTIPLIER * x) == round(CONST_MULTIPLIER * p.x) && round(CONST_MULTIPLIER * y) == round(CONST_MULTIPLIER * p.y);}

double Point::operator / (const Point & p) const {return sqrt(pow(p.x - x, 2.0) + pow(p.y - y, 2.0));}

Point Point::operator + (const Point & p) const {return Point(x + p.x, y + p.y);}
Point Point::operator + (const Vector & v) const {return Point(x + v.length * cos(v.angle), y + v.length * sin(v.angle));}

Point Point::operator - (const Point & p) const {return Point(x - p.x, y - p.y);}
Point Point::operator - (const Vector & v) const {return * this + -v;}

Vector Point::operator >= (const Point & p) const {
    const Point q(* this - p);
    return Vector(atan(q.y / q.x), ORIGIN / q);
}
Vector Point::operator <= (const Point & p) const {return p >= * this;}

bool Point::withinCone (const Point & origin, const Vector & center, double angle) const {
    return (* this / origin <= center.length) &&
            (fabs(center.angle - (* this >= origin).angle) <= 0.5 * angle);
}