#include "../../../src/model/world/world.h"
#include "../../../src/model/object/entity/individual/fred/fred.h"

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
            int freds = 3;
            double foodE = 10.0;
            double fredE = 20.0;

            world.addFood(new Food(10, 20, foodE));
            world.addIndividual<Fred>(40.0, 50.0, 0.0, fredE);
            world.addIndividual<Fred>(40, 50, 0, fredE);
            world.addIndividual<Fred>(40, 50, 0, fredE);

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
                world.fillWithFood([foodE](World * world) -> Food * {
                    return new Food(0, 0, std::min(foodE, world->getEnergy()));
                });

                THEN ("the amount of food and energy rises further") {
                    CHECK(world.getIndividuals().size() == 3);

//                    CHECK(world.getFood().size() > 1);
//                    CHECK(world.getEnergy() == world.ENERGY);
                }

                THEN ("adding more entities raises an overflow exception") {
//                    CHECK_THROWS_AS(world.addFood(new Food(0, 0, 10)), std::overflow_error);
//                    CHECK_THROWS_AS(world.addIndividual<Fred>(0, 0, 0, 10), std::overflow_error);
                }
            }

            double sizeI = world.getIndividuals().size();
            double sizeC = world.getCemetery().size();

            CHECK(sizeI > 0);
            CHECK(sizeC == 0);

            WHEN("I kill all individuals") {
                for (auto * individual : world.getIndividuals()) {
                    world.kill(individual->getID());

                    THEN("The individuals get buried in the cemetery") {
                        CHECK(world.getIndividuals().size() == --sizeI);
                        CHECK(world.getCemetery().size() == ++sizeC);
                    }
                }

                THEN("The energy level of the world isn't maximised anymore") {
                    CHECK(world.getEnergy() < world.ENERGY);
                }

                WHEN("A new individual arises") {
                    auto newborn = world.addIndividual<Fred>(0, 0, 0, fredE);
                    THEN("The new individual has a new ID") {
                        CHECK(newborn.getID() == freds);
                    }
                }
            }
        }
    }
}

SCENARIO("Objects in a World can be retrieved through range / position checks") {
    GIVEN ("A fully instantiated World") {
        double X, Y, E = 1000;
        X = Y = 100;
        World world (X, Y, E);

        WHEN ("I add equally spaced Individuals") {
            for (int y = 5; y < Y; y += 10) {
                for (int x = 5; x < X; x += 10) {
                    world.addIndividual<Fred>(x, y, 0, 5);
                }
            }

            // Fill with Food outside the world
            world.fillWithFood([](World * w) {return new Food (-10, -10, 1);});

            THEN ("Only an expected amount of entities is found around the centre of the map") {
                Point centre (0.5 * X, 0.5 * Y);

                CHECK (world.getObjectsAround(centre, 15)->size() == 4);
                CHECK (world.getObjectsAround(centre, 20)->size() == 12);
            }

            THEN ("Only an expected amount of entities is found in a specific cone rooted at the corner of the map") {
                Point corner = ORIGIN;

                CHECK (world.getObjectsInCone(corner, Vector (45, 20), Angle (90))->size() == 3);
                CHECK (world.getObjectsInCone(corner, Vector (45, 40), Angle (90))->size() == 13);
            }
        }
    }
}
