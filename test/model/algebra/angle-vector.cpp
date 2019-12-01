#include "../../../src/model/algebra/algebra.h"

#include <catch2/catch.hpp>
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

    SECTION ("Angles can be added to and subtracted from Vectors") {
        std::vector<Vector> vectors;
        vectors.emplace_back (0, 10);
        vectors.emplace_back (90, 10);
        vectors.emplace_back (180, 10);
        vectors.emplace_back (270, 10);

        std::vector<Angle> angles;
        angles.emplace_back (0);
        angles.emplace_back (90);
        angles.emplace_back (180);
        angles.emplace_back (270);

        unsigned long I = vectors.size();
        unsigned long J = angles.size();
        for (unsigned long i = 0; i < I; i++) {
            for (unsigned long j = 0; j < J; j++) {
                CHECK (vectors[i] + angles[j] == vectors[(i + j) % I]);
                CHECK (vectors[i] - angles[j] == vectors[(I + i - j) % I]);
            }
        }
    }

    SECTION ("Angles can be added and assigned in a single statement") {
        Vector v (0, 10);

        v += Angle (45);
        CHECK (v.angle.degrees() == 45);
        CHECK (coarseEquals(v.length, 10.0));

        v += Angle (15);
        CHECK (v.angle.degrees() == 60);
        CHECK (coarseEquals(v.length, 10.0));
    }
}
