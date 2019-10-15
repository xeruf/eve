//
// Created by janek on 17.09.19.
//

#ifndef EVE_WORLD_H
#define EVE_WORLD_H

#include "../object/entity/food/food.h"
#include "../object/entity/individual/individual.h"

#include <vector>
#include <stdexcept>
#include <experimental/random>
#include <string>

#define MAX_FOOD_SIZE 50

class World {
private:
    int energy = 0;

    std::vector<Food> food;
    std::vector<Individual> individuals;

    void incEnergy(Entity & entity);

public:
    const int WIDTH;
    const int HEIGHT;

    const int ENERGY;

    World(int WIDTH, int HEIGHT, int ENERGY);

    std::vector<Food> getFood();
    void addFood(Food * food);

    std::vector<Individual> getIndividuals();
    void addIndividual(Individual * individual);
};

#endif //EVE_WORLD_H
