#ifndef EVE_BRANDY_H
#define EVE_BRANDY_H

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"
#include "../../../../random/random.h"

class Brandy : public Individual {
public:
    /** Constructs a new individual of species Species
     * @param ID is unique and set automatically by the World
     * @param x is the latitude of the object
     * @param y is the longitude of the object
     * @param a is the direction it's looking
     * @param energy is its life source */
    Brandy(long ID, double x, double y, double a, double energy);
    /** Constructs a new individual of species Species
     * @param ID is unique and set automatically by the World
     * @param position sets the coordinates of Species
     * @param a is the direction it's looking
     * @param energy is its life source */
    Brandy(long ID, Point position, double a, double energy);

    Brandy * reproduce (long ID) override;

    /** Returns a random Action. */
    Action act(const std::unique_ptr<std::vector<Object *>> & visibles) override;
};


#endif //EVE_BRANDY_H
