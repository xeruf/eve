//
// Created by aaron on 27/09/2019.
//

#ifndef EVE_CONTROLLER_H
#define EVE_CONTROLLER_H

#include "../model/world/world.h"
#include "../model/object/entity/food/food.h"
#include "../model/object/entity/individual/individual.h"

#include <vector>

class Controller {
private:
    World world;
public:
    Controller(int WIDTH, int HEIGHT, int ENERGY);
};

#endif //EVE_CONTROLLER_H
