#ifndef EVE_ACTION_H
#define EVE_ACTION_H

#include "../object/entity/entity.h"

#include <stdexcept>
#include <string>

// List of possible actions. SIZE is used for iterative purpose
enum action {eat, move, sleep, SIZE};

struct Action {
    const action type;
    std::string name();

    Action(action type);
};

std::string actionName(action type);

#endif //EVE_ACTION_H
