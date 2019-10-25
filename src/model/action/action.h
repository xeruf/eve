#ifndef EVE_ACTION_H
#define EVE_ACTION_H

#include "../object/entity/entity.h"

struct Action {
    virtual ~Action() = 0;
};

struct Eat : Action {
};

struct Sleep : Action {
    ~Sleep();
};

struct Move : Action {
};


#endif //EVE_ACTION_H
