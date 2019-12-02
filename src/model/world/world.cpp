#include "world.h"

World::World(double WIDTH, double HEIGHT, double ENERGY) :
    WIDTH{WIDTH},
    HEIGHT{HEIGHT},
    ENERGY{ENERGY}
{
    if (WIDTH <= 0) throw std::range_error("World(): WIDTH must be positive");
    if (HEIGHT <= 0) throw std::range_error("World(): HEIGHT must be positive");
    if (ENERGY <= 0) throw std::range_error("World(): ENERGY must be positive");
}

World::~World() {
    for (auto food : foods) delete food;
    for (auto individual : individuals) delete individual;
    for (auto obstacle : obstacles) delete obstacle;
    for (auto corpse : cemetery) delete corpse;
}

void World::addFood(Food * food) {
    foods.push_back(food);
    incEnergy(food);
}

void World::incEnergy(Entity * entity) {
    if (energy + entity->getEnergy() > ENERGY) throw std::overflow_error("World::incEnergy(): operation exceeds ENERGY");
    energy += entity->getEnergy();
}

double World::getEnergy() const {
    return energy;
}

std::vector<Food *> World::getFood() const {
    return foods;
}

std::vector<Individual *> World::getIndividuals() const {
    return individuals;
}

std::unique_ptr<std::vector<Object *>> World::getObjectsAround(const Point & position, double radius) const {
    std::unique_ptr<std::vector<Object *>> visibles(new std::vector<Object *>);
    for (auto & object : foods) {
        if (std::abs(object->getPosition().distanceTo(position)) < radius) {
            visibles->push_back(object);
        }
    }
    for (auto & object : individuals) {
        if (std::abs(object->getPosition().distanceTo(position)) < radius) {
            visibles->push_back(object);
        }
    }
    for (auto & object : obstacles) {
        if (std::abs(object->getPosition().distanceTo(position)) < radius) {
            visibles->push_back(object);
        }
    }
    return visibles;
}

void World::setRefillFunction(const std::function<Food * (World * world)> & f) {
    refillFunction = f;
}

bool World::fillWithFood(const std::function<Food * (World * world)> & f) {
    try {
        while (energy < ENERGY) addFood(f(this));
        return true;
    } catch (std::overflow_error & e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

bool World::fillWithFood() {
    return fillWithFood(refillFunction);
}

std::list<Individual *> World::getCemetery() const {
    return cemetery;
}

bool World::kill(long ID) {
    unsigned long index = 0;
    for (auto individual : individuals) {
        if (individual->getID() == ID) {
            energy -= individual->getEnergy();
            cemetery.push_back(individual);
            individuals.erase(individuals.begin() + index);
            return true;
        }
        index++;
    }
    return false;
}