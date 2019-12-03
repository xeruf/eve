#include "fred.h"
#define INITIAL_MEMORY 10
#define NUMBER_OF_ACTIONS 4
#define ACTION_BASE_PROB 0.1

Fred::Fred(long ID, double x, double y, double a, double energy) :
        Fred(ID, Point(x, y), a, energy) {}

Fred::Fred(long ID, Point position, double a, double energy) :
        Individual(ID, position, a, energy), previousEnergy{energy} {
    memory.insert({SLEEP, INITIAL_MEMORY});
    memory.insert({MOVE, INITIAL_MEMORY});
    memory.insert({TURN_LEFT, INITIAL_MEMORY});
    memory.insert({TURN_RIGHT, INITIAL_MEMORY});
}

Action Fred::act(const std::unique_ptr<std::vector<Object *>> &visibles) {
    double currentEnergy = getEnergy();
    double energyDiff = sqrt(std::abs(currentEnergy - previousEnergy));
    double reward = sizeof(visibles) + ((currentEnergy - previousEnergy > 0) ? energyDiff : -energyDiff);
    for (int i = 0; i < MEMORY_SIZE; ++i) {
        int index = (actionCounter - i) % MEMORY_SIZE;
        memory[previousActions[index]] = memory[previousActions[index]] + reward * (MEMORY_SIZE - i) / 10;
    }
    previousEnergy = currentEnergy;

    action action = think(visibles);
    previousActions[actionCounter] = action;
    actionCounter = (actionCounter + 1) % MEMORY_SIZE;
    return Action(action);
}

action Fred::think(const std::unique_ptr<std::vector<Object *>> &visibles) {
    std::vector<double> normalizedMemory(NUMBER_OF_ACTIONS, 0);
    double normalizer = memory[SLEEP] + memory[MOVE] + memory[TURN_RIGHT] + memory[TURN_LEFT];
    for (int i = 0; i < NUMBER_OF_ACTIONS; i++) {
        normalizedMemory[i] = memory[(action) i] / normalizer + ACTION_BASE_PROB;
    }

    double rand = Uniform(0, 1 + ACTION_BASE_PROB * NUMBER_OF_ACTIONS).rand();
    if (rand <= normalizedMemory[0]) {
        return MOVE;
    } else if (rand <= normalizedMemory[0] + normalizedMemory[1]) {
        return TURN_LEFT;
    } else if (rand <= normalizedMemory[0] + normalizedMemory[1] + normalizedMemory[2]) {
        return TURN_RIGHT;
    }
    return SLEEP;
}

