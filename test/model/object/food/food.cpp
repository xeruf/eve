#include "../../../../src/model/object/food/food.h"
#include "../../../catch.hpp"


TEST_CASE("Construct food", "[food]") {
    Food food1 = Food(10, 20, 30);
    REQUIRE(food1.getValue() == 30);
    REQUIRE(food1.getPosition() == Point(10, 20));

    Food food2 = Food(Point(-100, 200), 10);
    REQUIRE(food2.getValue() == 10);
    REQUIRE(food2.getPosition().x == -100);
    REQUIRE(food2.getPosition().y == 200);

    REQUIRE_THROWS_AS(Food(0, 0, -10), std::range_error);
}
