#include <catch2/catch.hpp>
#include <exception>
#include <cmath>

#include "../../../../../../src/model/object/entity/individual/fred/fred.h"

SCENARIO("Fred can be created and initialized") {
    GIVEN("A fred and a test list of visible objects is instantiated") {
        Fred fred = Fred(3, 5, 0, 60);
        std::vector<Object *> list;

        WHEN("The individual is requested to act") {
            THEN("The method should not throw an error") {
                REQUIRE_NOTHROW(delete fred.act(& list));
                //Action();
            }
        }
    }
}