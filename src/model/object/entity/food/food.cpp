#include "food.h"

Food::Food(double x, double y, double energy) : Entity(x, y, energy) {}
Food::Food(Point position, double energy) : Entity(position.x, position.y, energy) {}

Food::Entity::~Entity() = default;

std::ostream & operator << (std::ostream & os, Food const & food) {
    return os << "Food (x: " << food.getPosition().x << ", y: " << food.getPosition().y << ", e: " << food.getEnergy() << ")";
}