#include "algebra_conf.h"

bool compare (double a, double b) {return fabs(b - a) < fabs(EPSILON);}
