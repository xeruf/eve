#include <catch2/catch.hpp>
#include <exception>
#include <cmath>

#include "../../../../../../src/model/object/entity/individual/fred/fred.h"

SCENARIO("Fred can be created and initialized") {
    GIVEN("An individual of class Fred with basic properties is instantiated") {
        Fred fred = Fred(3, 5, 60);

        WHEN("The individual is requested to act") {
            THEN("The method should not throw an error") {
                REQUIRE_NOTHROW(fred.act());
            }
        }
    }
}