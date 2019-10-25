#ifndef EVE_ACTION_H
#define EVE_ACTION_H

#include "../object/entity/entity.h"

struct Action {
    virtual ~Action() = 0;
};


struct Eat : Action {
    Action(const Entity * food) : food{food} {}

    const Entity * food;
};

struct Sleep : Action {

};

struct Move : Action {

};

return new Eat(somePointer);

#endif //EVE_ACTION_H
