#include "../../../src/model/algebra/algebra.h"

#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("Points and Vectors can be used interchangeably") {
    Point p (1, 1);
    Vector vp (p);
    Point pvp (vp);

    SECTION ("Points and Vectors can be created from each other") {
        CHECK (p == vp);
        CHECK (p == pvp);
        CHECK (vp == p);
        CHECK (vp == pvp);
        CHECK (pvp == p);
        CHECK (pvp == vp);
    }
}