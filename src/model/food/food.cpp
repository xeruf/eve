//
// Created by janek on 17.09.19.
//

#include "food.h"

Food::Food(int value) {
    this->value = value;
}

Food::Food() = default;

int Food::getValue() {
    return value;
}
