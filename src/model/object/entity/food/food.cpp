//
// Created by janek on 17.09.19.
//

#include <stdexcept>
#include "food.h"

void Food::checkValue() {
    if (value <= 0) throw std::range_error("Food can't have a negative value");
}

int Food::getValue() {return value;}
