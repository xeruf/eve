#ifndef EVE_CONTROLLER_H
#define EVE_CONTROLLER_H

#include "../model/object/entity/food/food.h"
#include "../model/object/entity/individual/fred/fred.h"
#include "../view/terminalview.h"
#include "../model/world/world.h"

#include <cmath>
#include <experimental/random>
#include <stdexcept>
#include <vector>

#define MAX_FOOD_SIZE 100.0

class Controller {
private:
    long iteration = 0;
    bool initialised = false;

    bool simulate();
public:
    World world;
    TerminalView terminalview;

    Controller(double WIDTH, double HEIGHT, double ENERGY);

    void init();
    long run();
};

#endif //EVE_CONTROLLER_H
