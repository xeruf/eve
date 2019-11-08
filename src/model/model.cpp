#include "model.h"

/* Point Math */
Point::Point(double x, double y) : x{x}, y{y} {}

// static cast double -> long to circumvent rounding errors
bool Point::operator == (const Point & p) const {return (long) x == (long) p.x && (long) y == (long) p.y;}

double Point::operator / (const Point & p) const {return sqrt(pow(p.x - x, 2.0) + pow(p.y - y, 2.0));}

Point Point::operator + (const Point & p) const {return Point(x + p.x, y + p.y);}
Point Point::operator + (const Vector & v) const {return Point(x + v.length * cos(v.angle), y + v.length * sin(v.angle));}

Point Point::operator - (const Point & p) const {return Point(x - p.x, y - p.y);}
Point Point::operator - (const Vector & v) const {return Point(x - v.length * cos(v.angle), y - v.length * sin(v.angle));}

Vector Point::operator , (const Point & p) const {
    const Point q(* this - p);
    return Vector(atan(q.y / q.x), ORIGIN / q);
}
Vector Point::operator >= (const Point & p) const {return * this, p;}
Vector Point::operator <= (const Point & p) const {return p, * this;}

/* Vector Math */
Vector::Vector(double a, double l) : angle{(a < 0) ? a + M_PI : a}, length{fabs(l)} {}
Vector::Vector(Point p) : Vector(atan(p.y / p.x), ORIGIN / p) {}
Vector::Vector(int a, double l) : Vector(((double) a / 180 * M_PI), l) {}

bool Vector::operator == (const Vector & v) const {return (long) angle == (long) v.angle && (long) length == (long) v.length;}
bool Vector::operator == (const Point & p) const {return * this == (ORIGIN, p);}

Vector Vector::operator + (const Vector & v) const {return Vector(ORIGIN + * this + v);}

Vector Vector::operator - () const {return Vector(ORIGIN - * this);}
Vector Vector::operator - (const Vector & v) const {return * this + -v;}
