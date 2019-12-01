#include "fred.h"

Fred::Fred(long ID, double x, double y, double a, double energy) :
        Individual(ID, x, y, a, energy) {}

Fred::Fred(long ID, Point position, double a, double energy) :
    Individual(ID, position, a, energy) {}

Action Fred::act(const std::unique_ptr<std::vector<Object *>> & visibles) {
    return Action((action) floor(Uniform(0, 4).rand()));
}