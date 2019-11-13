#include "../../../src/model/world/world.h"
#include "../../../src/model/object/entity/individual/fred/fred.h"
#include "../../../src/model/algebra/algebra.h"

#include <catch2/catch.hpp>
#include <exception>
#include <cmath>

SCENARIO("A world can be created and initialised") {
    GIVEN("An empty world is instantiated") {
        CHECK_THROWS_AS(World(-10, -20, 30), std::range_error);
        CHECK_THROWS_AS(World(40, 0, -60), std::range_error);
        CHECK_THROWS_AS(World(40, 50, 0), std::range_error);

        static double worldE = 100;
        World world = World(1000, 1000, worldE);

        CHECK(world.getFood().empty());
        CHECK(world.getIndividuals().empty());
        CHECK(not world.getEnergy());

        WHEN ("I add entities to the world") {
            static double foodE = 10;
            static double fredE = 20;

            world.addFood(new Food(10, 20, foodE));
            world.addIndividual(new Fred(40, 50, 0, fredE));
            world.addIndividual(new Fred(40, 50, 0, fredE));
            world.addIndividual(new Fred(40, 50, 0, fredE));

            THEN ("the object gets stored properly") {
                CHECK(world.getFood().back()->getPosition() == Point(10, 20));
                CHECK(world.getIndividuals().back()->getEnergy() == fredE);

                auto individuals = world.getIndividuals();
                long ID = individuals[0]->getID();
                for (auto fred : world.getIndividuals()) CHECK(fred->getID() == ID++);
            }

            THEN ("the amount of things in the world increases") {
                CHECK(world.getFood().size() == 1);
                CHECK(world.getIndividuals().size() == 3);
            }

            THEN ("the energy level rises") {
                CHECK(world.getEnergy() == foodE + 3 * fredE);
            }

            WHEN ("I fill up to max ENERGY") {
                world.fillWithFood([](World * world) -> Food * {
                    return new Food(0, 0, std::min(foodE, world->getEnergy()));
                });

                THEN ("the amount of food and energy rises further") {
                    CHECK(world.getIndividuals().size() == 3);

                    CHECK(world.getFood().size() > 1);
                    CHECK(world.getEnergy() == world.ENERGY);
                }

                THEN ("adding more entities raises an overflow exception") {
                    CHECK_THROWS_AS(world.addFood(new Food(0, 0, 10)), std::overflow_error);
                    CHECK_THROWS_AS(world.addIndividual(new Fred(0, 0, 0, 10)), std::overflow_error);
                }
            }

            double sizeI = world.getIndividuals().size();
            double sizeC = world.getCemetery().size();

            CHECK(sizeI > 0);
            CHECK(sizeC == 0);

            WHEN("I kill all individuals again") {
                for (auto individual : world.getIndividuals()) {
                    world.kill(individual->getID());

                    THEN("The individuals get buried in the cemetery") {
                        CHECK(world.getIndividuals().size() == --sizeI);
                        CHECK(world.getCemetery().size() == ++sizeC);
                    }
                }

                THEN("All individuals reside in the cemetery instead") {
                    CHECK(world.getIndividuals().empty());
                }

                THEN("The energy level of the world isn't maximised anymore") {
                    CHECK(world.getEnergy() < world.ENERGY);
                }
            }
        }
    }
}

