#include <iostream>
#include "model//world/world.h"
#include "model/object/food/food.h"
#include <experimental/random>

int main() {
    auto world = new World();
    for (int j = 0; j < 4; ++j) {
        world->addFood(new Food(0, 0, std::experimental::randint(0, 50)));
    }
    for (int i = 0; i < world->getSize(); ++i) {
        std::cout << world->getFood()[i].getValue() << std::endl;
    }
    int test;
    std::cin >> test;
    return test;
}