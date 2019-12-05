#include "fred.h"

Fred::Fred(long ID, double x, double y, double a, double energy) :
        Fred(ID, Point (x, y), a, energy) {}

Fred::Fred(long ID, Point position, double a, double energy) :
    Individual(ID, position, a, energy), previousActions(SLEEP), previousEnergy{energy} {
    memory.insert({SLEEP, 1});
    memory.insert({MOVE, 1});
    memory.insert({TURN_LEFT, 1});
    memory.insert({TURN_RIGHT, 1});
}

Fred * Fred::reproduce(long ID) {
    double energy = getEnergy();
    updateEnergy(1 - REPRODUCTION_CHILD_FRACTION);
    return new Fred (ID, position, getVision().angle.radians(), REPRODUCTION_CHILD_FRACTION * energy);
}

Action Fred::act(const std::unique_ptr<std::vector<Object *>> & visibles) {
    double currentEnergy = getEnergy();
    if (currentEnergy < previousEnergy) {
        memory[previousActions] = memory[previousActions] - 10;
    } else if (currentEnergy > previousEnergy) {
        memory[previousActions] = memory[previousActions] + 10;
    }
    previousEnergy = currentEnergy;

    action action = think(visibles);
    previousActions = action;
    return Action(action);
}

action Fred::think(const std::unique_ptr<std::vector<Object *>> &visibles) {
    std::vector<double> normalizedMemory(4, 0);
    double normalizer = memory[SLEEP] + memory[MOVE] + memory[TURN_RIGHT] + memory[TURN_LEFT];
    for (int i=0; i < memory.size(); i++) {
       normalizedMemory[i] = memory[(action) i] / normalizer;
    }

    double rand = Uniform(0, 1).rand();
    if (rand <= normalizedMemory[0]){
        return MOVE;
    } else if (rand <= normalizedMemory[0] + normalizedMemory[1]) {
        return TURN_LEFT;
    } else if (rand <= normalizedMemory[0] + normalizedMemory[1] + normalizedMemory[2]) {
        return TURN_RIGHT;
    }
    return SLEEP;
}

