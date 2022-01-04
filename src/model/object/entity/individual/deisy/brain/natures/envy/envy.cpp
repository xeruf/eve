#include "envy.h"

Envy::Envy (Individual const * body) : Brain (body) {}

Action Envy::think (const std::unique_ptr <std::vector <Object *>> & visibles) {
    Entity const * envee = nullptr;
    for (auto const * object : * visibles) if (((Entity *) object)->getEnergy() >= MAX_FOOD_SIZE) {
        envee = (Entity const *) object;
        break;
    }
    if (!envee) {
        if (body->getEnergy() > REPRODUCTION_THRESHOLD) return Action (REPRODUCE);
        if (visibles->size() > visiblesLimit) return Action (MOVE);
        double random = dice.rand();
        if (random < ENVY_MOVE_WEIGHT) return Action (MOVE);
        return Action ((turnLeft == (ENVY_MOVE_WEIGHT <= random < ENVY_TURN_WEIGHT)) ? TURN_LEFT : TURN_RIGHT);
    }

    if (envee->getPosition().withinCone(body->getPosition(), body->getVision() - Angle (MOUTH_ANGLE) * 0.15, Angle (MOUTH_ANGLE) * 0.3)) return Action (TURN_RIGHT);
    if (envee->getPosition().withinCone(body->getPosition(), body->getVision(), Angle (MOUTH_ANGLE) * 0.4)) return Action (SLEEP);
    if (envee->getPosition().withinCone(body->getPosition(), body->getVision() + Angle (MOUTH_ANGLE) * 0.15, Angle (MOUTH_ANGLE) * 0.3)) return Action (TURN_LEFT);
    return Action (MOVE);
}

