#ifndef EVE_WORLD_H
#define EVE_WORLD_H

#include "../object/entity/food/food.h"
#include "../object/entity/individual/individual.h"
#include "../object/obstacle/obstacle.h"
#include "../algebra/algebra.h"
#include "../random/random.h"

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

/** Enumeration as key to the different distributions pre-stored in the world */
enum Distribution_e {
    X_d, Y_d, DIRECTION_d, ENERGY_d
};

/** This class holds all information about everything (all objects - obstacles, individuals and entities */
class World {
private:
    double totalEnergy = 0;

    std::function<Food *(World * world)> refillFunction = {};

    std::vector<Food *> foods;
    std::vector<Individual *> individuals;
    std::vector<Obstacle *> obstacles;
    std::list<Individual *> cemetery;

    std::vector<Uniform> distributions;

    /** Increases the internal energy level by the level of the given entity */
    void incEnergy(const Entity * entity);

    /** Removes the food at the specified index and returns its value */
    double removeFoodAt(unsigned int foodIndex, const Food * food);

public:
    /** The width of the world */
    const double WIDTH;
    /** The height of the world */
    const double HEIGHT;
    /** The maximum energy level of the world */
    const double ENERGY;

    /** Constructs a world with the given properties
     * @param WIDTH of the world
     * @param HEIGHT of the world
     * @param ENERGY (maximum level of energy from all objects) */
    World(double WIDTH, double HEIGHT, double ENERGY);

    ~World();

    /** Returns a random number based on the Distribution enum:
     * @X_d         a number along the width of the world
     * @Y_d         a number along the height of the world
     * @DIRECTION_d an angle in radians between [0; 2xPI)
     * @ENERGY_d    a number between minimum and maximum Food level */
    [[nodiscard]] double rand(Distribution_e d);

    /** Returns the current level of energy, the sum of all entities within */
    [[nodiscard]] double getEnergy() const;

    /** Returns an array containing all Food items */
    [[nodiscard]] const std::vector<Food *> & getFood() const;

    /** Returns an array containing all Individuals currently living in the world */
    [[nodiscard]] const std::vector<Individual *> & getIndividuals() const;

    /** Returns a list containing all Individuals which deceased already */
    [[nodiscard]] const std::list<Individual *> & getCemetery() const;

    /** Removes the given energy value from the total */
    void usedEnergy(double usage);

    /** Adds the Food vector given to the world */
    void addFood(Food * food);

    /** Removes the given food from the list of foods */
    bool remove(const Food * food);

    /** Copies the given Individual into the world */
    void addChild(Individual * individual);

    /** Kills the Individual with the given ID. Returns whether this operation was successful */
    bool kill(long ID);

    unsigned long nextId();

    /** Sets the function the world uses to refill itself,
     *  should the energy level fall below the maximum energy value.
     *  The function gets a pointer to this world and should return a pointer to a Food item on the heap.
     * @param f(x) is the function invoked by the world until the energy level equals the maximum level */
    void setRefillFunction(const std::function<Food *(World * world)> & f);

    /** Fills the world using a temporary refill function.
     *  The function gets a pointer to this world and should return a pointer to a Food item on the heap.
     * @param f(x) is the function invoked by the world until the energy level equals the maximum level */
    bool fillWithFood(const std::function<Food *(World * world)> & f);

    /** Refills the world using the set refill function until the internal energy level equals the maximum value */
    bool fillWithFood();

    /** Removes all food items within the given radius around the given Position and returns their accumulated value */
    [[nodiscard]] double removeFoodsAround(const Point & position, double radius);

    /** Returns a pointer to an array containing all food items within the given radius around the given Position */
    [[nodiscard]] std::unique_ptr<std::vector<Food *>>
    getFoodsAround(const Point & position, double radius) const;

    /** Returns a pointer to an array containing all objects within the given radius around the given Position */
    [[nodiscard]] std::unique_ptr<std::vector<Object *>>
    getObjectsAround(const Point & position, double radius) const;

    /** Returns a pointer to an array containing all objects within the given cone
     * @param apex is the peak of the cone, where the angle is located in
     * @param centre is the Vector from the apex through the middle of the cone
     * @param angle is the overall angle of the cone */
    [[nodiscard]] std::unique_ptr<std::vector<Object *>>
    getObjectsInCone(const Point & apex, Vector centre, Angle angle) const;

    /** Constructs an Individual of the given Species with the given parameters in the world */
    template<class Species>
    Species & addIndividual(Point position, double angle, double energy) {
        auto * individual = new Species(nextId(), position, angle, energy);
        individuals.push_back(individual);
        incEnergy(individual);
        return * individual;
    }

    /** Constructs an Individual of the given Species with the given parameters in the world */
    template<class Species>
    Species & addIndividual(double x, double y, double angle, double energy) {
        return addIndividual<Species>(Point(x, y), angle, energy);
    }

    /** Returns the given position, ensuring it's within the boundaries of the world */
    Point normalisePosition(Point position) const;
};

#endif //EVE_WORLD_H
