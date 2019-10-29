#ifndef EVE_WORLD_H
#define EVE_WORLD_H

#include "../object/entity/food/food.h"
#include "../object/entity/individual/individual.h"
#include "../object/obstacle/obstacle.h"

#include <cmath>
#include <functional>
#include <vector>
#include <stdexcept>
#include <experimental/random>
#include <string>
#include <list>

class World {
private:
    int energy = 0;

    std::function<Food * (World * world)> refillFunction = {};

    std::vector<Object *> * objectLists[3];

    std::vector<Food *> foods;
    std::vector<Individual *> individuals;
    std::vector<Obstacle *> obstacles;
    std::list<Individual *> cemetery;

    void incEnergy(Entity * entity);

public:
    const int WIDTH;
    const int HEIGHT;

    const int ENERGY;

    World(int WIDTH, int HEIGHT, int ENERGY);
    ~World();

    int getEnergy();

    std::vector<Food *> getFood();
    void addFood(Food * food);

    void setRefillFunction(const std::function<Food * (World * world)> & f);
    bool fillWithFood(const std::function<Food * (World * world)> & f);
    bool fillWithFood();

    std::vector<Individual *> getIndividuals();
    void addIndividual(Individual * individual);

    std::list<Individual *> getCemetery();
    bool kill(int ID);

    std::vector<Object *> * getObjectsAround(const Point & position, double radius);
};

#endif //EVE_WORLD_H
