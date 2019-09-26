//
// Created by janek on 17.09.19.
//

#include "food.h"

Food::Food(Point position, int value) : Object(position), value{value} {}
Food::Food(int x, int y, int value) : Object(x, y), value{value} {}
Food::~Food() = default;

int Food::getValue() {return value;}
