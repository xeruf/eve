#ifndef EVE_WORLD_H
#define EVE_WORLD_H

#include "../object/entity/food/food.h"
#include "../object/entity/individual/individual.h"
#include "../object/obstacle/obstacle.h"

#include <cmath>
#include <cstdarg>
#include <functional>
#include <vector>
#include <stdexcept>
#include <experimental/random>
#include <string>
#include <list>
#include <utility>
#include <memory>

class World {
private:
    double energy = 0;

    std::function<Food * (World * world)> refillFunction = {};

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

    [[nodiscard]] std::list<Individual *> getCemetery() const;
    bool kill(long ID);

    [[nodiscard]] std::unique_ptr<std::vector<Object *>> getObjectsAround(const Point & position, double radius) const;

    template <class Species>
    void addIndividual(Point position, double angle, double energy) {
        Species * individual = new Species(individuals.size(), position, angle, energy);
        individuals.push_back(individual);
        incEnergy(individual);
    }

    template <class Species>
    void addIndividual(double x, double y, double angle, double energy) {
        addIndividual<Species>(Point(x, y), angle, energy);
    }
};

#endif //EVE_WORLD_H
