#ifndef EVE_CONTROLLER_H
#define EVE_CONTROLLER_H

#include "../config.h"
#include "../model/object/entity/food/food.h"
#include "../model/object/entity/individual/fred/fred.h"
#include "../model/random/random.h"
#include "../view/terminalview.h"
#include "../model/world/world.h"
#include "thread_handler/thread_handler.h"

#include <cmath>
#include <stdexcept>
#include <vector>

class Controller {
private:
    ThreadHandler th = ThreadHandler(2);

    long iteration = 0;
    bool initialised = false;

    bool simulate();

public:
    World world;
    TerminalView terminalView;

    Controller(double WIDTH, double HEIGHT, double ENERGY);

    void init();
    long run();
};

#endif //EVE_CONTROLLER_H
