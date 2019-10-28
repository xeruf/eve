#ifndef EVE_ACTION_H
#define EVE_ACTION_H

#include "../object/entity/entity.h"

enum action {EAT, MOVE, SLEEP, SIZE};

struct Action {
    const action type;

    explicit Action(action type);
    virtual std::string toString() = 0;
};

struct Eat : Action {
    Eat();
    std::string toString();
};

struct Move : Action {
    Move();
    std::string toString();
};

struct Sleep : Action {
    Sleep();
    std::string toString();
};


#endif //EVE_ACTION_H
