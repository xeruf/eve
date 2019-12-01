#include "distribution.h"

Distribution::Distribution(unsigned int SEED) : mt(SEED), SEED{SEED} {}

Distribution::~Distribution() = default;

unsigned int generateSeed() {
    std::random_device rd;
    unsigned int seed = rd();
    return seed;
}
