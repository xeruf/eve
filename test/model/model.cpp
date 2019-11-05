#include "../../src/model/model.h"

#include <catch2/catch.hpp>
#include <exception>
#include <cmath>
#include <iostream>

SCENARIO("A plane and *MATH*") {
    GIVEN("Points and Vectors") {
        Point A = Point (1, 1);
        Point B = Point (2, 3);
        Point C = Point (-5, -10);

        CHECK(A - B == Point(-1, -2));
        CHECK(C + A == Point(-4, -9));
        CHECK(ORIGIN / (A + B) == 5);

        Vector r = Vector (180, 10);
        Vector s = Vector (M_PI, 10);
        Vector t = Vector (90, 10);
        Vector rt = r + t;
        Vector RT = Vector(135, sqrt(200));

        CHECK(r == s);
        CHECK(rt == RT);
    }
}
