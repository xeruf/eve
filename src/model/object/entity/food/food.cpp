//
// Created by janek on 17.09.19.
//

#include "food.h"

Food::Food(Point position, int value) : Entity(position), value{value} {checkValue();}
Food::Food(int x, int y, int value) : Entity(x, y), value{value} {checkValue();}
Food::Entity::~Entity() = default;

Shape Food::getHitBox() {
    return Shape();
}

void Food::checkValue() {
    if (value <= 0) throw std::range_error("Food can't have a negative value");
}

int Food::getValue() {return value;}
