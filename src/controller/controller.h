#ifndef EVE_CONTROLLER_H
#define EVE_CONTROLLER_H

#include "../model/object/entity/food/food.h"
#include "../model/object/entity/individual/fred/fred.h"
#include "../model/world/world.h"

#include <cmath>
#include <experimental/random>
#include <stdexcept>
#include <vector>

#define MAX_FOOD_SIZE 100

class Controller {
private:
    int iteration = 0;
    bool initialised = false;

    bool simulate();
public:
    World world;

    Controller(int WIDTH, int HEIGHT, int ENERGY);

    void init();
    int run();
};

#endif //EVE_CONTROLLER_H
