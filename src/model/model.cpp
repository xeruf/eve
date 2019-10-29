#include "model.h"

Point::Point(double x, double y) : x{x}, y{y} {}

bool Point::operator == (const Point & p) {return x == p.x && y == p.y;}
double Point::operator / (const Point & p) {return sqrt(pow(p.x - x, 2.0) + pow(p.y - y, 2.0));}
Point Point::operator - (const Point & p) {return Point(x - p.x, y - p.y);}
Point Point::operator + (const Point & p) {return Point(x + p.x, y + p.y);}
