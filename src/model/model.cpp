#include "model.h"

Point::Point(int x, int y) : x{x}, y{y} {}

bool operator == (const Point & a, const Point & b) {return a.x == b.x && a.y == b.y;}
double operator / (const Point & a, const Point & b) {return sqrt(pow(b.x - a.x, 2.0) + pow(b.y - a.y, 2.0));}
Point operator - (const Point & a, const Point & b) {return Point(a.x - b.x, a.y - b.y);}
Point operator + (const Point & a, const Point & b) {return Point(a.x + b.x, a.y + b.y);}
