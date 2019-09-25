//
// Created by janek on 17.09.19.
//

#include "world.h"

Food *World::getFood() {
    return food;
}

void World::addFood(Food *food) {
    this->food[foodIndex++] = *food;
}

int World::getSize() {
    return foodIndex;
}
