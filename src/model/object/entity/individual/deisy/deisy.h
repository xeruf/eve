#ifndef EVE_DEISY_H
#define EVE_DEISY_H

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"
#include "../../../../color/color.h"

/** Autonomous Species */
class Deisy : public Individual {
    static const int DEFAULT_COLOR = DEISY_COLOR;

public:
    /** Constructs a new individual of species Deisy
     * @param ID is unique and set automatically by the World
     * @param position sets the coordinates of Deisy
     * @param a is the direction it's looking
     * @param energy is its life source */
    Deisy(long ID, Point position, double a, double energy);
    /** Constructs a new individual of species Deisy
     * @param ID is unique and set automatically by the World
     * @param position sets the coordinates of Deisy
     * @param a is the direction it's looking
     * @param energy is its life source */
    Deisy(long ID, Point position, double a, double energy, int color);

    int getColor () override;

    Deisy * reproduce (unsigned long ID) override;

    /** Waits for a key input in stdin and then returns an action based on that key. */
    Action act(const std::unique_ptr<std::vector<Object *>> & visibles) override;
};

#endif //EVE_DEISY_H
