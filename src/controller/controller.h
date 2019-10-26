#ifndef EVE_CONTROLLER_H
#define EVE_CONTROLLER_H

#include "../model/object/entity/food/food.h"
#include "../model/object/entity/individual/fred/fred.h"
#include "../model/random/random.h"
#include "../model/world/world.h"

#include <cmath>
#include <stdexcept>
#include <typeinfo>
#include <vector>

#define MIN_FOOD_SIZE 10.0
#define MAX_FOOD_SIZE 100.0

class Controller {
private:
    long iteration = 0;
    bool initialised = false;

    bool simulate();
public:
    World world;

    Controller(double WIDTH, double HEIGHT, double ENERGY);

    void init();
    long run();
};

#endif //EVE_CONTROLLER_H
