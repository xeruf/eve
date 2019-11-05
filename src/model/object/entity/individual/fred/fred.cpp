#include "fred.h"

Fred::Fred(double x, double y, double a, double energy) : Individual(x, y, a, energy) {}

Action * Fred::act(std::vector<Object *> * visibles) {
    return new Sleep();
}