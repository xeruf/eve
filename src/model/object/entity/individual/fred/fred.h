#ifndef EVE_FRED_H
#define EVE_FRED_H

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"
#include "../../../../random/random.h"

#include <unordered_map>

/** Species using a basic reinforcement algorithm */
class Fred : public Individual {
private:
    action previousActions;
    double previousEnergy;
    std::unordered_map<action, double> memory;

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

    Fred * reproduce (long ID) override;

    /** Determines the action to take based on Reinforcement Learning. */
    Action act(const std::unique_ptr<std::vector<Object *>> & visibles) override;
};

#endif //EVE_FRED_H
