#ifndef EVE_FRED_H
#define EVE_FRED_H

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"
#include "../../../../random/random.h"

#include <unordered_map>

/** Non-Player-controlled Species using a basic reinforcement algorithm to supposedly act *smart**/
class Fred : public Individual {
private:
    static const int color = FRED_COLOR;

    action previousActions;
    double previousEnergy;
    std::unordered_map<action, double> memory;

    action think (const std::unique_ptr<std::vector<Object *>> & visibles);
public:
    /** Constructs a new individual of species Fred
     * @param ID is unique and set automatically by the World
     * @param x is the latitude of the object
     * @param y is the longitude of the object
     * @param a is the direction it's looking
     * @param energy is its life source */
    Fred (long ID, double x, double y, double a, double energy);
    /** Constructs a new individual of species Fred
     * @param ID is unique and set automatically by the World
     * @param position sets the coordinates of Fred
     * @param a is the direction it's looking
     * @param energy is its life source */
    Fred (long ID, Point position, double a, double energy);

    int getColor () override;

    /** Methods giving birth to an offspring */
    Fred * reproduce (long ID) override;

    /** Returns an Action using Neural Networks, and Machine, Deep and Reinforcement Learning
     * @param visibles is a pointer to an array holding all objects within its vision
     * @return the chosen Action */
    Action act (const std::unique_ptr<std::vector<Object *>> & visibles) override;
};

#endif //EVE_FRED_H
