#include "sloth.h"

Sloth::Sloth (Individual const * body) : Brain (body) {}

Action Sloth::think (const std::unique_ptr <std::vector <Object *>> & visibles) {
    double random = dice.rand();
    if (random < SLOTH_MOVE_WEIGHT) return Action (MOVE);
    if (dice.rand() < SLOTH_CHANGE_DIR) turnLeft = !turnLeft;
    if (random < SLOTH_MOVE_WEIGHT + SLOTH_TURN_WEIGHT) return Action (turnLeft ? TURN_LEFT : TURN_RIGHT);
    return Action (SLEEP);
}

