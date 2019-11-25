#include "../../../src/model/algebra/algebra.h"

#include <catch2/catch.hpp>
#include <cmath>
#include <iostream>
#include <vector>

TEST_CASE ("Angles and Vectors can be used together for arithmetic and logic operations") {
    SECTION ("Angles can be compared to the angle of a Vector") {
        Vector v (90, 10);
        Vector w (180, 10);
        Angle a (90);
        Angle b (180);

        CHECK (v == a);
        CHECK (a == v);
        CHECK (w == b);
        CHECK (b == w);

        CHECK (v != b);
        CHECK (b != v);
        CHECK (w != a);
        CHECK (a != w);
    }
}
