#ifndef EVE_ACTION_H
#define EVE_ACTION_H

#include "../object/entity/entity.h"

enum action {
    MOVE, SLEEP, TURN_LEFT, TURN_RIGHT
};

struct Action {
    const action type;

    explicit Action(action type);

    std::string toString();;
};


#endif //EVE_ACTION_H
