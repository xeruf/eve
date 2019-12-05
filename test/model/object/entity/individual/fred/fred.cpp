#include <catch2/catch.hpp>
#include <exception>
#include <cmath>

#include "../../../../../../src/model/object/entity/individual/fred/fred.h"

SCENARIO("Fred can be created and initialized") {
    GIVEN("A fred and a test list of visible objects is instantiated") {
        Fred fred(0, ORIGIN, 0, INDIVIDUAL_START_SIZE);

        WHEN("The individual is requested to act") {
            THEN("The method should not throw an error") {
                std::unique_ptr<std::vector<Object *>> list (new std::vector<Object *>);
                REQUIRE_NOTHROW(fred.act(list));
            }
        }
    }
}

SCENARIO("Fred can reproduce") {
    GIVEN("A Fred") {
        auto energy = REPRODUCTION_THRESHOLD;
        Fred fred(0, ORIGIN, 0, energy);
        auto child = *fred.reproduce(1);
        REQUIRE(fred.getEnergy() == energy * (1 - REPRODUCTION_CHILD_FRACTION));
        REQUIRE(child.getID() == 1);
        REQUIRE(child.getEnergy() == energy * REPRODUCTION_CHILD_FRACTION);
    }
}