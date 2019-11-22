#include "../../../../src/model/algebra/angle/angle.h"

#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("Angles can substitute doubles while keeping between [0; 2 * PI)") {
    // 0 degrees ANGLES
    std::vector<Angle> A;
    A.emplace_back(0.0);
    A.emplace_back(0);
    A.emplace_back(-360);
    A.emplace_back(360);
    A.emplace_back(720);
    A.emplace_back(2 * M_PI);

    Angle & a = A[0];

    // 90 degrees ANGLES
    std::vector<Angle> B;
    B.emplace_back(0.5 * M_PI);
    B.emplace_back(90);
    B.emplace_back(450);
    B.emplace_back(-270);

    Angle & b = B[0];

    // 180 degrees ANGLES
    std::vector<Angle> C;
    C.emplace_back(M_PI);
    C.emplace_back(180);
    C.emplace_back(-180);

    Angle & c = C[0];

    // 270 degrees ANGLES
    std::vector<Angle> D;
    D.emplace_back(1.5 * M_PI);
    D.emplace_back(270);
    D.emplace_back(-90);

    Angle & d = D[0];

    std::vector<std::vector<Angle>> ANGLES;
    ANGLES.push_back(A);
    ANGLES.push_back(B);
    ANGLES.push_back(C);
    ANGLES.push_back(D);

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
}
