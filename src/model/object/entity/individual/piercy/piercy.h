#ifndef EVE_PIERCY_H
#define EVE_PIERCY_H

#define FLUSH_AMOUNT 1000

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"
#include "../../../../color//color.h"

#include <iostream>
#include <limits>
#include <memory>

/** Player-controller Species */
class Piercy : public Individual {
    static const int DEFAULT_COLOR = PIERCY_COLOR;

public:
    /** Constructs a new individual of species Piercy
     * @param ID is unique and set automatically by the World
     * @param position sets the coordinates of Piercy
     * @param a is the direction it's looking
     * @param energy is its life source */
    Piercy (long ID, Point position, double a, double energy);
    /** Constructs a new individual of species Piercy
     * @param ID is unique and set automatically by the World
     * @param position sets the coordinates of Piercy
     * @param a is the direction it's looking
     * @param energy is its life source */
    Piercy (long ID, Point position, double a, double energy, int color);

    int getColor () override;

    /** Methods giving birth to an offspring */
    Piercy * reproduce (long ID) override;

    /** Returns an Action using Neural Networks, and Machine, Deep and Reinforcement Learning
     * @param visibles is a pointer to an array holding all objects within its vision
     * @return the chosen Action */
    Action act (const std::unique_ptr<std::vector<Object *>> & visibles) override;
};

#endif //EVE_PIERCY_H
