#ifndef EVE_BRANDY_H
#define EVE_BRANDY_H

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"
#include "../../../../random/random.h"

/** Non-Player-controlled Species performing completely random actions */
class Brandy : public Individual {
private:
    static const int color = BRANDY_COLOR;

public:
    /** Constructs a new individual of species Brandy
     * @param ID is unique and set automatically by the World
     * @param x is the latitude of the object
     * @param y is the longitude of the object
     * @param a is the direction it's looking
     * @param energy is its life source */
    Brandy (long ID, double x, double y, double a, double energy);
    /** Constructs a new individual of species Brandy
     * @param ID is unique and set automatically by the World
     * @param position sets the coordinates of Brandy
     * @param a is the direction it's looking
     * @param energy is its life source */
    Brandy (long ID, Point position, double a, double energy);

    int getColor () override {return color;}

    /** Methods giving birth to an offspring */
    Brandy * reproduce (long ID) override;

    /** Returns an Action using Neural Networks, and Machine, Deep and Reinforcement Learning
     * @param visibles is a pointer to an array holding all objects within its vision
     * @return the chosen Action */
    Action act (const std::unique_ptr<std::vector<Object *>> & visibles) override;
};


#endif //EVE_BRANDY_H
