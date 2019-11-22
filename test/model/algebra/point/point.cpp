#include "../../../../src/model/algebra/point/point.h"

#include <catch2/catch.hpp>
#include <vector>

static std::vector<Point> getPoints ();

TEST_CASE("Points can be used for calculations and simple arithmetic") {
    auto POINTS = getPoints();

    SECTION ("Points get instantiated correctly") {
        CHECK (POINTS[2].x == 4.0);
        CHECK (POINTS[2].y == 2.0);

        CHECK (POINTS[3].x == -1.0);
        CHECK (POINTS[3].y == -1.0);
    }

    SECTION ("Points can be added and subtracted") {
        CHECK (POINTS[0] + POINTS[0] == POINTS[1]);
        CHECK (POINTS[3] + POINTS[0] == ORIGIN);

        CHECK (POINTS[2] - POINTS[2] == ORIGIN);
        CHECK (POINTS[1] - POINTS[0] == POINTS[0]);
    }

    SECTION ("Dividing Points returns their distance") {
        CHECK (POINTS[2] / POINTS[1] == 2);
    }
}

static std::vector<Point> getPoints () {
    static std::vector<Point> POINTS;
    POINTS.emplace_back(1, 1);
    POINTS.emplace_back(2, 2);
    POINTS.emplace_back(4, 2);
    POINTS.emplace_back(-1, -1);

    return POINTS;
}
