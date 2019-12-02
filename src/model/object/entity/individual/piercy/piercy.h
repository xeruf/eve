#ifndef EVE_PIERCY_H
#define EVE_PIERCY_H

#define FLUSH_AMOUNT 1000

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"

#include <iostream>
#include <limits>
#include <memory>

class Piercy : public Individual {
public:
    Piercy(long ID, double x, double y, double a, double energy);
    Piercy(long ID, Point position, double a, double energy);

    Action act(const std::unique_ptr<std::vector<Object *>> & visibles) override;
};

#endif //EVE_PIERCY_H
