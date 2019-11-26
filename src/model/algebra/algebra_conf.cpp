#include "algebra_conf.h"

bool coarseEquals (double a, double b) {return fabs(b - a) < fabs(EPSILON);}
