#include "../../../src/model/food/food.h"
#include "../../catch.hpp"

TEST_CASE("Construct food", "[food]") {
    REQUIRE(Food(30).getValue() == 30);
}