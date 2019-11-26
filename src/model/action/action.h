#ifndef EVE_ACTION_H
#define EVE_ACTION_H

#include "../object/entity/entity.h"

enum action {
    MOVE, SLEEP, TURN_LEFT, TURN_RIGHT
};

struct Action {
    const action type;

    explicit Action(action type);
    virtual ~Action() = 0;

    std::string toString() {
        switch (type) {
            case MOVE: return "move";
            case SLEEP: return "sleep";
            case TURN_LEFT: return "turn_left";
            case TURN_RIGHT: return "turn_right";
        }
    };
};


#endif //EVE_ACTION_H
