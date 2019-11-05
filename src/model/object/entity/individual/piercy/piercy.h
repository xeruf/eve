#ifndef EVE_PIERCY_H
#define EVE_PIERCY_H

#define FLUSH_AMOUNT 1000

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"

#include <iostream>
#include <limits>

class Piercy : public Individual {
public:
    Piercy(double x, double y, double a, double energy);

    Action * act(std::vector<Object *> * visibles);
};

#endif //EVE_PIERCY_H
