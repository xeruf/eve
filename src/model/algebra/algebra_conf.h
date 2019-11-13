#ifndef EVE_ALGEBRA_CONF_H
#define EVE_ALGEBRA_CONF_H

#define EPSILON 0.00000001

#include <cmath>

bool compare (double a, double b) {return fabs(b - a) < fabs(EPSILON);}

struct Angle;
struct Point;
struct Vector;

#endif //EVE_ALGEBRA_CONF_H
