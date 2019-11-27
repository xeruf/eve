#include "../../../src/model/random/random.h"

#include <catch2/catch.hpp>
#include <exception>
#include <cmath>

#include <string.h>

#define TESTING_CYCLES 1000000
#define LOWER_BOUND -1000
#define UPPER_BOUND 1000
#define DEVIATION 0.0001 * TESTING_CYCLES
#define EXPECTATION (double) TESTING_CYCLES / (UPPER_BOUND - LOWER_BOUND)

TEST_CASE ("A Distribution can be instantiated with a specific seed") {
    auto uniform = Uniform(LOWER_BOUND, UPPER_BOUND, 0);

    double storage [UPPER_BOUND - LOWER_BOUND];
    memset (storage, 0, sizeof(storage));

    for (int i = 0; i < TESTING_CYCLES; i++) {
        double test = uniform.rand();
        REQUIRE (true);
        storage [(int) floor (test) - LOWER_BOUND]++;
    }

    int i = LOWER_BOUND;
    for (auto sum : storage) {
        CHECK (fabs (sum - EXPECTATION) < DEVIATION);
    }
}

