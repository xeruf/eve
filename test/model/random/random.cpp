#include "../../../src/model/random/random.h"

#include <catch2/catch.hpp>
#include <exception>

SCENARIO("A Distribution can be instantiated with a specific or random seed") {
    auto uniform = Uniform<double>(0, 100);
    double testU = uniform.rand();
    CHECK(0 <= testU);
    CHECK(testU <= 100);
}

