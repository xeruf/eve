#include "action.h"

Action::Action(action type) : type{type} {}

std::string Action::toString() {
    switch (type) {
        case MOVE: return "move";
        case SLEEP: return "sleep";
        case TURN_LEFT: return "turn_left";
        case TURN_RIGHT: return "turn_right";
        case REPRODUCE: return "reproduce";
    }
    throw std::logic_error ("This can't be happening...");
}
