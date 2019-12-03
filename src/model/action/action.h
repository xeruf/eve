#ifndef EVE_ACTION_H
#define EVE_ACTION_H

#include "../object/entity/entity.h"

/** Enumeration defining the different possible actions */
enum action {
    MOVE, SLEEP, TURN_LEFT, TURN_RIGHT
};

/** Struct as container for different actions */
struct Action {
    const action type;

    /** Constructs an Action based on the given type (an action enum) */
    explicit Action(action type);

    /** Returns a string representation of the action */
    std::string toString();;
};


#endif //EVE_ACTION_H
