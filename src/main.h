#ifndef EVE_MAIN_H
#define EVE_MAIN_H

#include "controller/controller.h"

#define WIDTH  1920.0
#define HEIGHT 1080.0

/// Maximum sum of energy of all objects in the system. Increase for more entites.
/// Adjust carefully. This is known to cause overflow errors if too big
#define ENERGY 250000.0

#endif //EVE_MAIN_H
