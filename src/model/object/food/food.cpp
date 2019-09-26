//
// Created by janek on 17.09.19.
//

#include <stdexcept>
#include "food.h"

Food::Food() : Object(0, 0), value{std::experimental::randint(1, 50)} {}
Food::Food(Point position, int value) : Object(position), value{value} {checkValue();}
Food::Food(int x, int y, int value) : Object(x, y), value{value} {checkValue();}
Food::~Food() = default;

void Food::checkValue() {
    if (value <= 0) throw std::range_error("Food can't have a negative value");
}

int Food::getValue() {return value;}
