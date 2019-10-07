#include "../../../../../src/model/object/entity/food/food.h"
#include <catch2/catch.hpp>
#include <exception>

SCENARIO("Food can be created", "[food]") {
    GIVEN("Food is created with different values") {
        REQUIRE(Food(0, 4, 10).getValue() == 10);
        REQUIRE_THROWS_AS(Food(20, -400, -10), std::range_error);
    }
}
