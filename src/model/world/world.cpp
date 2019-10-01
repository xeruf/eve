//
// Created by janek on 17.09.19.
//

#include "world.h"

World::World() = default;

std::vector<Food> World::getFood() {
    return foods;
}

void World::addFood(Food & food) {
    foods.push_back(food);
}
