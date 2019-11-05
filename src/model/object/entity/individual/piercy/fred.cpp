#include "fred.h"

Piercy::Piercy(double x, double y, double energy) : Individual(x, y, energy) {}

Piercy::Individual::~Individual() = default;

Action * Piercy::act(std::vector<Object *> * visibles) {
    return new Sleep();
}