#include "fred.h"

Fred::Fred(long ID, double x, double y, double a, double energy) :
    Individual(ID, x, y, a, energy) {}

Action * Fred::act(const std::unique_ptr<std::vector<Object *>> & visibles) {
    return new Action(SLEEP);
}