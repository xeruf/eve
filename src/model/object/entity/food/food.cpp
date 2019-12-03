#include "food.h"

Food::Food (double x, double y, double energy) :
    Entity (x, y, energy) {}

Food::Food (Point position, double energy) :
    Entity (position.x, position.y, energy) {}

Food::Entity::~Entity() = default;
