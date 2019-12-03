#include "brandy.h"

Brandy::Brandy (long ID, double x, double y, double a, double energy) :
        Individual (ID, x, y, a, energy) {}

Brandy::Brandy (long ID, Point position, double a, double energy) :
        Individual (ID, position, a, energy) {}

Brandy * Brandy::reproduce (long ID) {
    double energy = getEnergy();
    updateEnergy (1 - REPRODUCTION_CHILD_FRACTION);
    return new Brandy (ID, position, getVision().angle.radians(), REPRODUCTION_CHILD_FRACTION * energy);
}

Action Brandy::act (const std::unique_ptr<std::vector<Object *>> & visibles) {
    return Action ( (action) Uniform (0, 4).rand());
}
