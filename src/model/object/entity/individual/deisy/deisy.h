#ifndef EVE_DEISY_H
#define EVE_DEISY_H

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"
#include "../../../../color/color.h"
#include "../../../../random/random.h"

namespace deisy {
enum NATURE {LUST, GLUTTONY, GREED, SLOTH, WRATH, ENVY, PRIDE};
static unsigned long const COLOR[] {CLUST, CGLUTTONY, CGREED, CSLOTH, CWRATH, CENVY, CPRIDE};
}

/** Autonomous Species */
class Deisy : public Individual {
    static const int DEFAULT_COLOR = DEISY_COLOR;

    const deisy::NATURE nature;

    Deisy(long ID, Point position, double a, double energy, int color, deisy::NATURE nature);

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

static Uniform NatureDist {0, 7};

#endif //EVE_DEISY_H
