#include "lust.h"

Action Lust::think(const std::unique_ptr<std::vector<Object *> > & visibles, double energy) {
    if (energy > REPRODUCTION_THRESHOLD) return Action (REPRODUCE);

    return Action ((action) std::floor (Uniform (0, 4).rand()));
}

