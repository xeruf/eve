#include "fred.h"

Fred::Fred(double x, double y, double a, double energy) : Individual(x, y, a, energy) {}

Fred::Individual::~Individual() = default;

Action * Fred::act(std::vector<Object *> * visibles) {
    return new Sleep();
}