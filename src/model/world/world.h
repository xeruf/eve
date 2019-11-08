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
    double energy = 0;

    std::function<Food * (World * world)> refillFunction = {};

    std::vector<Object *> * objectLists[3];

    std::vector<Food *> foods;
    std::vector<Individual *> individuals;
    std::vector<Obstacle *> obstacles;
    std::list<Individual *> cemetery;

    void incEnergy(Entity * entity);

public:
    const double WIDTH;
    const double HEIGHT;

    const double ENERGY;

    World(double WIDTH, double HEIGHT, double ENERGY);
    ~World();

    [[nodiscard]] double getEnergy() const;

    [[nodiscard]] std::vector<Food *> getFood() const;
    void addFood(Food * food);

    void setRefillFunction(const std::function<Food * (World * world)> & f);
    bool fillWithFood(const std::function<Food * (World * world)> & f);
    bool fillWithFood();

    [[nodiscard]] std::vector<Individual *> getIndividuals() const;
    void addIndividual(Individual * individual);

    std::list<Individual *> getCemetery() const;
    bool kill(long ID);

    [[nodiscard]] std::vector<Object *> * getObjectsAround(const Point & position, double radius) const;
};

#endif //EVE_WORLD_H
