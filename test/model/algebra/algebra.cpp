#include "../../../src/model/algebra/algebra.h"
#include "../../../src/model/random/random.h"

#include <catch2/catch.hpp>
#include <iostream>
#include <vector>

#define DIST_EXTREMES 10000.0

TEST_CASE("Points and Vectors can be used interchangeably") {
    Uniform dist = Uniform (- DIST_EXTREMES, DIST_EXTREMES, 1208015009);
    double x = dist.rand();
    double y = dist.rand();
    std::cout << "SEED: " << dist.SEED << std::endl;
    std::cout << "P (" << x << "|" << y << ")\n";

    Point p (x, y);
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