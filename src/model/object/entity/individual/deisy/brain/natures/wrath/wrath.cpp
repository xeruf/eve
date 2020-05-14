#include "wrath.h"

Wrath::Wrath (Individual const * body) : Brain (body) {}

Action Wrath::think (const std::unique_ptr <std::vector <Object *>> & visibles) {
    Entity const * followee = nullptr;
    for (auto const * object : * visibles) if (((Entity *) object)->getEnergy() >= MAX_FOOD_SIZE) {
        followee = (Entity const *) object;
        break;
    }
    if (!followee) {
        if (body->getEnergy() >  WRATH_REPRODUCTION_MODIFIER * REPRODUCTION_THRESHOLD) return Action (REPRODUCE);
        if (visibles->size() > visiblesLimit) return Action (MOVE);
        double random = dice.rand();
        if (random < WRATH_MOVE_WEIGHT) return Action (MOVE);
        return Action ((turnLeft == (WRATH_MOVE_WEIGHT <= random < WRATH_TURN_WEIGHT)) ? TURN_LEFT : TURN_RIGHT);
    }

    if (followee->getPosition().withinCone(body->getPosition(), body->getVision() - Angle (MOUTH_ANGLE) * 0.15, Angle (MOUTH_ANGLE) * 0.3)) return Action (TURN_LEFT);
    if (followee->getPosition().withinCone(body->getPosition(), body->getVision(), Angle (MOUTH_ANGLE) * 0.4)) return Action (MOVE);
    if (followee->getPosition().withinCone(body->getPosition(), body->getVision() + Angle (MOUTH_ANGLE) * 0.15, Angle (MOUTH_ANGLE) * 0.3)) return Action (TURN_RIGHT);
    return Action (SLEEP);
}

