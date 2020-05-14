#ifndef EVE_ACTION_H
#define EVE_ACTION_H

#include "../object/entity/entity.h"

#define NUMBER_OF_ACTIONS 5

/** Enumeration defining the different possible actions */
enum action {
    SLEEP, MOVE, TURN_LEFT, TURN_RIGHT, REPRODUCE
};

/** Struct as container for different actions */
struct Action {
    action type;

    /** Constructs an Action based on the given type (an action enum) */
    explicit Action(action type);

    Action (Action const & other) = default;

    /** Returns a string representation of the action */
    std::string toString();
};


#endif //EVE_ACTION_H
