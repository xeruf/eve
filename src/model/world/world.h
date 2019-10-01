//
// Created by janek on 17.09.19.
//

#ifndef EVE_WORLD_H
#define EVE_WORLD_H

#include "../object/food/food.h"
#include "../object/entity/individual.h"

#include <vector>

class World {
private:
    std::vector<Food> foods;
    std::vector<Individual> individuals;
public:
    World();

    void addFood(Food &);
    std::vector<Food> getFood();
};

#endif //EVE_WORLD_H
