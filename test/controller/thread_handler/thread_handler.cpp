#include "../../../src/controller/thread_handler/thread_handler.h"
#include <catch2/catch.hpp>

SCENARIO("A ThreadHandler can be instantiated") {
    GIVEN("The ThreadHandler is instantiated with the right amount of threads") {

        REQUIRE(ThreadHandler().getThreadAmount() > 0);
    }
}
