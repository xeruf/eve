#include "../../../src/model/world/world.h"
#include "../../../src/model/object/entity/individual/fred/fred.h"
#include "../../../src/model/model.h"

#include <catch2/catch.hpp>
#include <exception>
#include <cmath>

SCENARIO("A world can be created and initialised") {
    GIVEN("An empty world is instantiated") {
        REQUIRE_THROWS_AS(World(-10, -20, 30), std::range_error);
        REQUIRE_THROWS_AS(World(40, 0, -60), std::range_error);
        REQUIRE_THROWS_AS(World(40, 50, 0), std::range_error);

        int worldE = 100;
        World world = World(1000, 1000, worldE);

        REQUIRE(world.getFood().empty());
        REQUIRE(world.getIndividuals().empty());
        REQUIRE(not world.getEnergy());

        WHEN ("I add entities to the world") {
            static int foodE = 10;
            static int fredE = 20;

            world.addFood(new Food(10, 20, foodE));
            world.addIndividual(new Fred(40, 50, fredE));
            world.addIndividual(new Fred(40, 50, fredE));
            world.addIndividual(new Fred(40, 50, fredE));

            THEN ("the object gets stored properly") {
                REQUIRE(world.getFood().back()->getPosition() == Point(10, 20));
                REQUIRE(world.getIndividuals().back()->getEnergy() == fredE);

                int ID = 0;
                for (auto fred : world.getIndividuals()) REQUIRE(fred->getID() == ID++);
            }

            THEN ("the amount of things in the world increases") {
                REQUIRE(world.getFood().size() == 1);
                REQUIRE(world.getIndividuals().size() == 3);
            }

            THEN ("the energy level rises") {
                REQUIRE(world.getEnergy() == foodE + 3 * fredE);
            }

            WHEN ("I fill up to max ENERGY") {
                world.fillWithFood([](int energy) -> Food * {
                    return new Food(0, 0, std::min(foodE, energy));
                });

                THEN ("the amount of food and energy rises further") {
                    REQUIRE(world.getIndividuals().size() == 3);

                    REQUIRE(world.getFood().size() > 1);
                    REQUIRE(world.getEnergy() == world.ENERGY);
                }

                THEN ("adding more entities raises an overflow exception") {
                    REQUIRE_THROWS_AS(world.addFood(new Food(0, 0, 10)), std::overflow_error);
                    REQUIRE_THROWS_AS(world.addIndividual(new Fred(0, 0, 10)), std::overflow_error);
                }
            }
        }
    }
}