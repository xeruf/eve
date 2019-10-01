#include "../../catch.hpp"
#include "../../../src/model/world/world.h"

TEST_CASE("Construct world", "[world]") {
    World world = World();
    Food food = Food(0, 0, 10);
    world.addFood(food);
    REQUIRE(world.getFood().size() == 1);
    REQUIRE(world.getFood()[0].getValue() == 10);
}
