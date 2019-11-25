#include "../../../src/model/algebra/algebra.h"
#include "../../../src/model/random/random.h"

#include <catch2/catch.hpp>
#include <cmath>
#include <iostream>
#include <vector>

#define DIST_EXTREMES 10000.0

TEST_CASE("Points and Vectors can be used interchangeably") {
    // TODO: CHECK why certain numbers (e.g. 1208015009) let the tests fail
    Uniform dist = Uniform (- DIST_EXTREMES, DIST_EXTREMES);
    double x = dist.rand();
    double y = dist.rand();
    std::cout << "SEED: " << dist.SEED << std::endl;

    SECTION ("Points and Vectors can be compared to") {
        Point p1(1, 1);
        Point p2(3, 4);

        Vector v1(45, sqrt(2.0));
        Vector v2(acos(0.6), 5);

        CHECK (p1 == v1);
        CHECK (v1 == p1);
        CHECK (p2 == v2);
        CHECK (v2 == p2);

        CHECK (p1 != v2);
        CHECK (v2 != p1);
        CHECK (p2 != v1);
        CHECK (v1 != p2);
    }

    SECTION ("Points and Vectors can be constructed from each other") {
        Point p(x, y);
        Vector vp(p);
        Point pvp(vp);

        CHECK (p == vp);
        CHECK (p == pvp);
        CHECK (vp == p);
        CHECK (vp == pvp);
        CHECK (pvp == p);
        CHECK (pvp == vp);
    }

    SECTION ("Points and Vectors can be assigned to each other") {
        Point p(x, y);
        Vector vp(ORIGIN);
        Point pvp(ORIGIN);

        vp = p;
        pvp = vp;

        CHECK (p == vp);
        CHECK (vp == pvp);
        CHECK (pvp == p);
    }


}