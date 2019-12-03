#ifndef EVE_FRED_H
#define EVE_FRED_H
#define MEMORY_SIZE 100

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"
#include "../../../../random/random.h"

#include <unordered_map>

/** NPC Species with Reinforcement Learning */
class Fred : public Individual {
private:
    std::unordered_map<action, double> memory;
    std::vector<action> previousActions = std::vector<action>(MEMORY_SIZE, SLEEP);
    double previousEnergy;
    int actionCounter = 0;

    action think(const std::unique_ptr<std::vector<Object *>> & visibles);
public:
    /** Constructs a new individual of species Fred
     * @param ID is unique and set automatically by the World
     * @param x is the latitude of the object
     * @param y is the longitude of the object
     * @param a is the direction it's looking
     * @param energy is its life source */
    Fred(long ID, double x, double y, double a, double energy);
    /** Constructs a new individual of species Fred
     * @param ID is unique and set automatically by the World
     * @param position sets the coordinates of Fred
     * @param a is the direction it's looking
     * @param energy is its life source */
    Fred(long ID, Point position, double a, double energy);

    /** Returns an Action using Neural Networks, and Machine, Deep and Reinforcement Learning
     * @param visibles is a pointer to an array holding all objects within its vision
     * @return the chosen Action */
    Action act(const std::unique_ptr<std::vector<Object *>> & visibles) override;
};

#endif //EVE_FRED_H
