#ifndef EVE_BRANDY_H
#define EVE_BRANDY_H

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"
#include "../../../../random/random.h"
#include "../../../../color/color.h"

/** Species performing completely random actions */
class Brandy : public Individual {
private:
    static const int DEFAULT_COLOR = BRANDY_COLOR;

public:
    /** Constructs a new individual of species Brandy
     * @param ID is unique and set automatically by the World
     * @param position sets the coordinates of Brandy
     * @param a is the direction it's looking
     * @param energy is its life source */
    Brandy(long ID, Point position, double a, double energy, int color);
    /** Constructs a new individual of species Brandy
     * @param ID is unique and set automatically by the World
     * @param position sets the coordinates of Brandy
     * @param a is the direction it's looking
     * @param energy is its life source */
    Brandy(long ID, Point position, double a, double energy);

    int getColor () override;

    Brandy * reproduce (unsigned long ID) override;

    /** Returns a random Action. */
    Action act(const std::unique_ptr<std::vector<Object *>> & visibles) override;
};


#endif //EVE_BRANDY_H
