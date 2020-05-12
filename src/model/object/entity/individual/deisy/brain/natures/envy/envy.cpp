#include "envy.h"

Action Envy::think(const std::unique_ptr<std::vector<Object *> > & visibles, double energy) {
    return Action ((action) Uniform (1, 5).rand());
}

