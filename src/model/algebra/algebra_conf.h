#ifndef EVE_ALGEBRA_CONF_H
#define EVE_ALGEBRA_CONF_H

#define EPSILON 0.00000001

#include <cmath>

/** Checks if two doubles are close to each other. The standard deviation is read from EPSILON */
bool coarseEquals (double a, double b);

struct Angle;
struct Point;
struct Vector;

#endif //EVE_ALGEBRA_CONF_H
