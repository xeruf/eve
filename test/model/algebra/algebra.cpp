#include "../../../src/model/algebra/algebra.h"

#include <catch2/catch.hpp>

TEST_CASE("Angles can substitute doubles while keeping between [0; 2 * PI)") {
    // 0 degrees angles
    Angle a1 {2 * M_PI};
    Angle a2 {0};
    Angle a3 {-360};
    Angle a4 {360};
    Angle a5 {0.0};

    // 90 degrees angles
    Angle b1 {0.5 * M_PI};
    Angle b2 {90};
    Angle b3 {450};
    Angle b4 {-270};

    // 180 degrees angles
    Angle c1 {M_PI};
    Angle c2 {180};
    Angle c3 {-180};

    // 270 degrees angles
    Angle d1 {1.5 * M_PI};
    Angle d2 {270};
    Angle d3 {-90};
}