#include "brandy.h"

Brandy::Brandy (long ID, Point position, double a, double energy) :
        Individual (ID, position, a, energy, DEFAULT_COLOR) {}

Brandy::Brandy (long ID, Point position, double a, double energy, int color) :
        Individual (ID, position, a, energy, color) {}

Brandy * Brandy::reproduce(unsigned long ID) {
    return new Brandy (ID, position, getVision().angle.radians(), reproductionSplit(), darken (color));
}

Action Brandy::act(const std::unique_ptr<std::vector<Object *>> & visibles) {
    return Action ((action) Uniform (0, 5).rand());
}

int Brandy::getColor() {
    return color;
}
