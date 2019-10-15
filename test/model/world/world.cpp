#include "../../../src/model/world/world.h"
#include "../../../src/model/object/entity/individual/fred/fred.h"
#include <catch2/catch.hpp>
#include <exception>

SCENARIO("A world can be created and initialised") {
    GIVEN("A world is instantiated") {
        REQUIRE_THROWS_AS(World(-10, -20, 30), std::range_error);
        REQUIRE_THROWS_AS(World(40, 50, -60), std::range_error);

        World world = World(1000, 1000, 100);
        int foodSize = world.getFood().size();
        int individuals = world.getIndividuals().size();

        WHEN ("I add entities to the world") {
            world.addFood(new Food(10, 20, 5));
            world.addIndividual(new Fred(40, 50, 10));

            THEN ("the amount of things in the world increase") {
                REQUIRE(world.getFood().size() == foodSize + 1);
                REQUIRE(world.getIndividuals().size() == individuals + 1);
            }
        }
    }
}