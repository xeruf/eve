#include "deisy.h"

Deisy::Deisy(long ID, Point position, double a, double energy) :
    Deisy(ID, position, a, energy, DEFAULT_COLOR) {}

Deisy::Deisy(long ID, Point position, double a, double energy, int color) :
    Deisy(ID, position, a, energy, color, (NATURE) std::floor (NatureDist.rand())) {}

Deisy::Deisy(long ID, Point position, double a, double energy, int color, NATURE nature) :
    Individual(ID, position, a, energy, COLOR_BY_NATURE ? COLOR [nature] : color),
    nature {nature} {}

Deisy * Deisy::reproduce(unsigned long ID) {
    return new Deisy (static_cast<long>(ID), position, getVision().angle.radians(), reproductionSplit(), darken (color), nature);
}

Action Deisy::act(const std::unique_ptr<std::vector<Object *>> & visibles) {
    return Action(MOVE);
}

int Deisy::getColor() {
    return color;
}
