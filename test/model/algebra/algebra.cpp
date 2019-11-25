#include "../../../src/model/algebra/algebra.h"
#include "../../../src/model/random/random.h"

#include <catch2/catch.hpp>
#include <iostream>
#include <vector>

#define DIST_EXTREMES 10000.0

TEST_CASE("Points and Vectors can be used interchangeably") {
    // TODO: CHECK why certain numbers (e.g. 1208015009) let the tests fail
    Uniform dist = Uniform (- DIST_EXTREMES, DIST_EXTREMES);
    double x = dist.rand();
    double y = dist.rand();
    std::cout << "SEED: " << dist.SEED << std::endl;

    SECTION ("Points and Vectors can be created from each other") {
        Point p (x, y);
        Vector vp (p);
        Point pvp (vp);

        CHECK (p == vp);
        CHECK (p == pvp);
        CHECK (vp == p);
        CHECK (vp == pvp);
        CHECK (pvp == p);
        CHECK (pvp == vp);

        p = vp;
        vp = pvp;
        CHECK (p == vp);
        CHECK (vp == pvp);
    }
}