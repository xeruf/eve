#include "greed.h"

Greed::Greed (Individual const * body) : Brain (body) {}

Action Greed::think (const std::unique_ptr <std::vector <Object *>> & visibles) {
    if (body->getEnergy() > GREED_REPRODUCTION_THRESHOLD_MULTIPLIER * REPRODUCTION_THRESHOLD) return Action (REPRODUCE);

    int left = 0;
    int middle = 0;
    int right = 0;
    for (auto * const object : * visibles) {
        if (((Entity *) object)->getEnergy() < MAX_FOOD_SIZE) {
            if (object->getPosition().distanceTo(body->getPosition()) <= 2 * body->getRadius()) return Action (MOVE);
            if (object->getPosition().withinCone(body->getPosition(), body->getVision() - sideAngle * 0.5, sideAngle)) ++left;
            if (object->getPosition().withinCone(body->getPosition(), body->getVision(), middleAngle)) ++middle;
            if (object->getPosition().withinCone(body->getPosition(), body->getVision() + sideAngle * 0.5, sideAngle)) ++right;
        }
    }

    if (left  > middle && left  >= right) return Action (TURN_LEFT);
    if (right > middle && right >= left)  return Action (TURN_RIGHT);
    return Action (MOVE);
}

