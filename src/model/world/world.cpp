//
// Created by janek on 17.09.19.
//

#include "world.h"

World::World(int WIDTH, int HEIGHT, int ENERGY) :
    WIDTH{WIDTH},
    HEIGHT{HEIGHT},
    ENERGY{ENERGY}
{
    if (WIDTH <= 0) throw std::range_error("World(): WIDTH must be positive");
    if (HEIGHT <= 0) throw std::range_error("World(): HEIGHT must be positive");
    if (ENERGY <= 0) throw std::range_error("World(): ENERGY must be positive");
}

World::~World() {
    for (int i = 0; i < food.size(); i++) delete food[i];
}

void World::addFood(Food * food) {
    (this->food).emplace_back(& * food);
    incEnergy(food);
}

void World::addIndividual(Individual * individual) {
    individuals.emplace_back(& * individual);
    incEnergy(individual);
}

void World::incEnergy(Entity * entity) {
    if (energy + entity->getEnergy() > ENERGY) throw std::exception();
    energy += entity->getEnergy();
}

std::vector<Food *> World::getFood() {
    return food;
}

std::vector<Individual *> World::getIndividuals() {
    return individuals;
}
