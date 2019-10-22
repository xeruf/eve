//
// Created by janek on 17.09.19.
//

#include "world.h"

World::World(int WIDTH, int HEIGHT, int ENERGY) : WIDTH{WIDTH}, HEIGHT{HEIGHT}, ENERGY{ENERGY} {
    if (WIDTH <= 0 || HEIGHT <= 0 || ENERGY <= 0) throw std::range_error("World initialising values must be positive!");
    fillUpEnergy();
}

void World::addFood(int x, int y, int value) {
    food.emplace_back(Food(x, y, value));
    energy += value;
}

void World::addFoodRandomly(int value) {
    addFood(std::experimental::randint(0, WIDTH), std::experimental::randint(0, HEIGHT), value);
}

void World::fillUpEnergy() {
    while(energy < ENERGY) {
        if (ENERGY - energy > MAX_FOOD_SIZE) addFoodRandomly(ENERGY - energy);
        else addFoodRandomly(std::experimental::randint(1, MAX_FOOD_SIZE));
    }
}

std::vector<Food> World::getFood() {
    return food;
}

std::vector<Individual> World::getIndividuals() {
    return individuals;
}
