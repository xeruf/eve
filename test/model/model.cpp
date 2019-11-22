#include "../../src/model/model.h"

#include <catch2/catch.hpp>
#include <exception>
#include <cmath>

SCENARIO("A plane and *MATH*") {
    GIVEN("Points and Vectors") {
        Point A = Point (1, 1);
        Point B = Point (2, 3);
        Point C = Point (-5, -10);
        Point D = Point (1, 11);

        Vector OD = Vector(D);
        Vector r = Vector (180, 10);
        Vector s = Vector (M_PI, 10);
        Vector t = Vector (90, 10);
        Vector rt = r + t;
        Vector RT = Vector(135, sqrt(200));

        CHECK(A - B == Point(-1, -2));
        CHECK(C + A == Point(-4, -9));
        CHECK(ORIGIN / (A + B) == 5);

        CHECK((A >= D) == t);
        CHECK((C >= A) == (A <= C));
        CHECK((B >= B) == ORIGIN);

        CHECK(OD == (ORIGIN >= D));

        CHECK(r == s);
        CHECK(rt == RT);
    }
}
