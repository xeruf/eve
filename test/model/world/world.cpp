#include "../../../src/model/world/world.h"
#include <catch2/catch.hpp>
#include <exception>

SCENARIO("A world can be created and initialised") {
    GIVEN("A world is instantiated") {
        REQUIRE_THROWS_AS(World(-10, -20, 30), std::range_error);
        REQUIRE_THROWS_AS(World(40, 50, -60), std::range_error);

        World world = World(1000, 1000, 100);
        REQUIRE(not world.getFood().empty());
    }
}