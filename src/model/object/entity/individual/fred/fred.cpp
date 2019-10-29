#include "fred.h"

Fred::Fred(double x, double y, double energy) : Individual(x, y, energy) {}

Fred::Individual::~Individual() = default;

Action * Fred::act(std::vector<Object *> * visibles) {
    return new Sleep();
}