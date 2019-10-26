#include "action.h"

Action::Action(action type) : type{type} {}

std::string Action::name() {return actionName(type);}

std::string actionName(action type) {
    switch(type) {
        case 0: return "eat";
        case 1: return "move";
        case 2: return "sleep";
        default: throw std::range_error("Invalid type of action");
    }
}

