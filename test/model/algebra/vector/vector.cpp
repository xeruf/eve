#include "../../../../src/model/algebra/vector/vector.h"

#include <catch2/catch.hpp>
#include <vector>

// TODO
TEST_CASE("Vectors can be used for calculations and simple arithmetic") {
    std::vector<Vector> VECTORS;
    VECTORS.emplace_back(90, 1.5);
    VECTORS.emplace_back(0.5 * M_PI, 1.5);
    VECTORS.emplace_back(M_PI, 4);
    VECTORS.emplace_back(135, 5);
    VECTORS.emplace_back(270, 1.5);
    VECTORS.emplace_back(270, -1.5);

    SECTION ("Vectors get instantiated correctly") {
        CHECK (VECTORS[4].angle == 1.5 * M_PI);
        CHECK (VECTORS[4].length == 1.5);

        CHECK (VECTORS[5].angle == 0.5 * M_PI);
        CHECK (VECTORS[5].length == 1.5);
    }

}
