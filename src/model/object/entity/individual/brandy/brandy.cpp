#include "brandy.h"

Brandy::Brandy (long ID, Point position, double a, double energy) :
        Individual (ID, position, a, energy, DEFAULT_COLOR) {}

Brandy::Brandy (long ID, Point position, double a, double energy, int color) :
        Individual (ID, position, a, energy, color) {}

Brandy * Brandy::reproduce(long ID) {
    double energy = getEnergy();
    updateEnergy(1 - REPRODUCTION_CHILD_FRACTION);
    return new Brandy (ID, position, getVision().angle.radians(), REPRODUCTION_CHILD_FRACTION * energy, darken (color));
}

Action Brandy::act(const std::unique_ptr<std::vector<Object *>> & visibles) {
    return Action ((action) Uniform (0, 4).rand());
}

int Brandy::getColor() {
    return color;
}
