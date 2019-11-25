#include "../../../../src/model/algebra/angle/angle.h"
#include "../angle-vector.h"

#include <catch2/catch.hpp>
#include <vector>


TEST_CASE("Angles can substitute doubles while keeping between [0; 2 * PI)") {
    auto ANGLES = getAngles();

    Angle & a = ANGLES[0][0];
    Angle & b = ANGLES[1][0];
    Angle & c = ANGLES[2][0];
    Angle & d = ANGLES[3][0];

    SECTION ("All angles are the same and within [0; 2 * PI)") {
        double iter_angle = 0.0;
        for (auto & angles : ANGLES) {
            for (auto & angle : angles) {
                CHECK (angle == angles[0]);
                CHECK (angle == iter_angle);
                CHECK (angle >= 0.0);
                CHECK (angle < 2 * M_PI);
            }
            iter_angle += 0.5 * M_PI;
        }
    }

    SECTION ("Angles can be compared with each other") {
        CHECK (a == a);
        CHECK (a != b);
        CHECK (!(a != a));
    }

    SECTION ("Simple algebra behaves the same as with doubles") {
        CHECK (b + c == d);
        CHECK (a - b == d);
        CHECK (b * 3.0 == d);
        CHECK (c / 2.0 == b);
    }

    SECTION ("Angles can be inverted") {
        CHECK (-b == d);
        CHECK (-c == c);
        CHECK (- - d == d);
    }

    SECTION ("Angles can be converted between radians and degrees") {
        CHECK (a.degrees() == 0);
        CHECK (a.radians() == 0.0);
        CHECK (a.radians() == Angle::toRadians(a.degrees()));
    }

    SECTION ("Angles can be updated with new angles in radians and degrees") {
        CHECK (a.update(90) == b);
        CHECK (b.update(M_PI) == c);
    }
}


