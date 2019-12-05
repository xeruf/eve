#ifndef EVE_COLOR_H
#define EVE_COLOR_H

#define COLOR_CHANGE_FRACTION 0.2

#include "../../config.h"

#include <cmath>

int darken (unsigned int color);
int darken (unsigned int color, double fraction);

#endif //EVE_COLOR_H
