#ifndef EVE_DEISY_H
#define EVE_DEISY_H

#include "brain/natures.h"
#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"
#include "../../../../color/color.h"
#include "../../../../random/random.h"

#include <memory>

/** Autonomous Species */
class Deisy : public Individual {
    static const int DEFAULT_COLOR = DEISY_COLOR;

    std::unique_ptr <Brain> brain;

    Deisy(long ID, Point position, double a, double energy, int color, brain::Nature nature);
    Deisy(long ID, Point position, double a, double energy, int color, brain::Nature nature, int);

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

    [[nodiscard]] int getColor () const;

    Deisy * reproduce (unsigned long ID) override;

    /** Waits for a key input in stdin and then returns an action based on that key. */
    Action act(const std::unique_ptr<std::vector<Object *>> & visibles) override;
};

static Uniform NatureDist {0, 7};


#endif //EVE_DEISY_H
