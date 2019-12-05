#include "fred.h"

Fred::Fred(long ID, Point position, double a, double energy) :
        Fred(ID, position, a, energy, DEFAULT_COLOR) {}

Fred::Fred(long ID, Point position, double a, double energy, int color) :
    Individual(ID, position, a, energy, color), previousActions(SLEEP), previousEnergy{energy} {
    memory.insert({SLEEP, 1});
    memory.insert({MOVE, 2});
    memory.insert({TURN_LEFT, 1});
    memory.insert({TURN_RIGHT, 1});
}

Fred * Fred::reproduce(long ID) {
    return new Fred (ID, position, getVision().angle.radians(), reproductionSplit(), darken (color));
}

Action Fred::act(const std::unique_ptr<std::vector<Object *>> & visibles) {
    double currentEnergy = getEnergy();
    if (currentEnergy < previousEnergy) {
        memory[previousActions] = memory[previousActions] / 2;
    } else if (currentEnergy > previousEnergy) {
        memory[previousActions] = memory[previousActions] + 2;
    }
    previousEnergy = currentEnergy;

    action action = think(visibles);
    previousActions = action;
    return Action(action);
}

action Fred::think(const std::unique_ptr<std::vector<Object *>> &visibles) {
    std::vector<double> normalizedMemory(4, 0);
    double normalizer = memory[SLEEP] + memory[MOVE] + memory[TURN_LEFT] + memory[TURN_RIGHT];
    for (int i=0; i < memory.size(); i++) {
       normalizedMemory[i] = memory[(action) i] / normalizer;
    }

    double rand = Uniform(0, 1).rand();
    if (rand <= normalizedMemory[0]){
        return SLEEP;
    } else if (rand <= normalizedMemory[0] + normalizedMemory[1]) {
        return MOVE;
    } else if (rand <= normalizedMemory[0] + normalizedMemory[1] + normalizedMemory[2]) {
        return TURN_LEFT;
    }
    return TURN_RIGHT;
}

int Fred::getColor() {
    return color;
}
