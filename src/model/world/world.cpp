//
// Created by janek on 17.09.19.
//

#include "world.h"

World::World(int WIDTH, int HEIGHT, int ENERGY) : WIDTH{WIDTH}, HEIGHT{HEIGHT}, ENERGY{ENERGY} {
    for (int i = 0; i < 3; i++) if ((& WIDTH)[i] > 0) throw std::range_error("World(): The " + std::to_string(i) + ". parameter must be positive!");
}

void World::addFood(Food * food) {
    (this->food).emplace_back(std::move(* food));
    incEnergy(* food);
}

void World::addIndividual(Individual * individual) {
    individuals.emplace_back(std::move(* individual));
    incEnergy(* individual);
}

void World::incEnergy(Entity & entity) {
    if (energy + entity.getEnergy() > ENERGY) throw std::exception();
    energy += entity.getEnergy();
}

std::vector<Food> World::getFood() {
    return food;
}

std::vector<Individual> World::getIndividuals() {
    return individuals;
}
