#include "deisy.h"

Deisy::Deisy(long ID, Point position, double a, double energy) :
        Individual(ID, position, a, energy, DEFAULT_COLOR) {}

Deisy::Deisy(long ID, Point position, double a, double energy, int color) :
    Individual(ID, position, a, energy, color) {}

Deisy * Deisy::reproduce(unsigned long ID) {
    return new Deisy (static_cast<long>(ID), position, getVision().angle.radians(), reproductionSplit(), darken (color));
}

Action Deisy::act(const std::unique_ptr<std::vector<Object *>> & visibles) {
    return Action(MOVE);
}

int Deisy::getColor() {
    return color;
}