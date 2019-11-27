#include <catch2/catch.hpp>
#include <exception>
#include <cmath>

#include "../../../../../../src/model/object/entity/individual/fred/fred.h"

SCENARIO("Fred can be created and initialized") {
    GIVEN("A fred and a test list of visible objects is instantiated") {
        Fred fred = Fred(0, 3.0, 5.0, 0.0, 60.0);

        WHEN("The individual is requested to act") {
            THEN("The method should not throw an error") {
                std::unique_ptr<std::vector<Object *>> list (new std::vector<Object *>);
                REQUIRE_NOTHROW(fred.act(list));
                //Action();
            }
        }
    }
}