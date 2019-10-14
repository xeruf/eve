//
// Created by janek on 17.09.19.
//

#include "food.h"

Food::Food(int x, int y, int energy) : Entity(x, y, energy) {}
//Food::Food(Point position, int energy) : Entity(position.x, position.y, energy) {}

Food::Entity::~Entity() = default;
