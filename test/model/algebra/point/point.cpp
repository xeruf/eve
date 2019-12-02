#include "../../../../src/model/algebra/algebra.h"

#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("Points can be used for calculations and simple arithmetic") {
    std::vector<Point> POINTS;
    POINTS.emplace_back(1, 1);
    POINTS.emplace_back(2, 2);
    POINTS.emplace_back(4, 2);
    POINTS.emplace_back(-1, -1);

    SECTION ("Points get instantiated correctly") {
        CHECK (POINTS[2].x == 4.0);
        CHECK (POINTS[2].y == 2.0);

        CHECK (POINTS[3].x == -1.0);
        CHECK (POINTS[3].y == -1.0);
    }

    GIVEN ("All points in 'POINTS' are distinctive") {
        SECTION ("Points can be compared") {
            for (unsigned long i = 0; i < POINTS.size(); i++) {
                for (unsigned long j = 0; j < POINTS.size(); j++) {
                    if (i == j) CHECK (POINTS[i] == POINTS[j]);
                    else CHECK (POINTS[i] != POINTS[j]);
                }
            }
        }
    }

    SECTION ("Points can be added and subtracted") {
        CHECK (POINTS[0] + POINTS[0] == POINTS[1]);
        CHECK (POINTS[3] + POINTS[0] == ORIGIN);

        CHECK (POINTS[2] - POINTS[2] == ORIGIN);
        CHECK (POINTS[1] - POINTS[0] == POINTS[0]);
    }

    SECTION ("Points can be updated from a vector in one operation") {
        Point p = ORIGIN;
        p += Vector (Point (3, 4));

        CHECK (coarseEquals(p.x, 3.0));
        CHECK (coarseEquals(p.y, 4.0));
    }

    SECTION ("Dividing Points returns their distance") {
        CHECK (POINTS[2].distanceTo(POINTS[1]) == 2);
    }
}

TEST_CASE ("A Point can check if it's within a cone") {
    GIVEN ("A Cone represented by a Point, Vector and Angle") {
        Point apex = ORIGIN;
        Vector centre (45, 4);
        Angle angle (90);

        std::vector<Point> valid;
        valid.emplace_back (1, 1);
        valid.emplace_back (0, 2);
        valid.emplace_back (4, 0);
        valid.emplace_back (3, 2);

        std::vector<Point> invalid;
        invalid.emplace_back (-2, -10);
        invalid.emplace_back (-1, -1);
        invalid.emplace_back (-2, -2);
        invalid.emplace_back (3, 3);
        invalid.emplace_back (2, 4);
        invalid.emplace_back (10, 10);
        invalid.emplace_back (1, -1);
        invalid.emplace_back (-1, 1);

        Vector t1 (ORIGIN.vectorTo(invalid[1]));
        Vector t2 (ORIGIN.vectorTo(invalid[2]));

        for (auto & point : valid) {
            CHECK (point.withinCone (apex, centre, angle));
        }
        for (auto & point : invalid) {
            CHECK (! point.withinCone (apex, centre, angle));
        }
    }
}