#include "fred.h"

Fred::Fred(double x, double y, double energy) : Individual(x, y, energy) {}

Action * Fred::act(std::vector<Object *> * visibles) {
    return new Sleep();
}