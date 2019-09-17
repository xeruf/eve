#include <iostream>
#include "test.h"
#include "world.h"
#include <experimental/random>

#define WIDTH 1000
#define HEIGHT 800

int main() {
    auto world = new World();
    for (int j = 0; j < 4; ++j) {
        world->addFood(new Food(std::experimental::randint(0, 50)));
    }
    for (int i = 0; i < world->getSize(); ++i) {
        std::cout << world->getFood()[i].getValue() << std::endl;
    }
    int test;
    std::cin >> test;
    return test;
}