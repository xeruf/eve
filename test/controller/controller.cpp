#include "../../src/controller/controller.h"

#include <catch2/catch.hpp>
#include <stdexcept>

SCENARIO("The Controller can be initialised") {
    GIVEN("An instance of a controller") {
        Controller controller = Controller(1000, 1000, 1000);

        WHEN ("I start the controller") {
            WHEN ("The controller isn't initialised yet") {
                THEN ("the controller throws an exception") {
                    REQUIRE_THROWS_AS(controller.run(), std::logic_error);
                }
            }

            controller.init();

            THEN ("It ends after a certain amount of generations") {
                REQUIRE(controller.run() >= 0);
            }
        }
    }
}
