#ifndef EVE_DISTRIBUTION_H
#define EVE_DISTRIBUTION_H

#include <random>

struct Distribution {
    Distribution(unsigned int SEED);
    virtual ~Distribution() = 0;

    const unsigned long SEED;
    std::mt19937 mt;
};

/** Returns a Seed guaranteed to be random */
unsigned int generateSeed();

#endif //EVE_DISTRIBUTION_H
