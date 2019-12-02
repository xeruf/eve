#ifndef EVE_UNIFORM_H
#define EVE_UNIFORM_H

#include "../distribution.h"

/** Uniform probabilistic distribution, provides a very random but seeded random generator */
struct Uniform : Distribution {
    std::uniform_real_distribution<double> realDistribution;

    const double LOWER_BOUND;
    const double UPPER_BOUND;

    /** Constructs a Random Generator generating numbers uniformly distributed. Randomly produces a seed
     *  @param LOWER_BOUND is the lowest possible number appearing
     *  @param UPPER_BOUND is the lowest number above LOWER_BOUND impossible to appear */
    Uniform(double LOWER_BOUND, double UPPER_BOUND) :
            Uniform(LOWER_BOUND, UPPER_BOUND, generateSeed()) {}

    /** Constructs a Random Generator generating numbers uniformly distributed, based on the seed given
     * @param LOWER_BOUND is the lowest possible number appearing
     * @param UPPER_BOUND is the lowers number above LOWER_BOUND impossible to appear
     * @param SEED is determining the resulting numbers; the same SEED always results in the same numbers */
    Uniform(double LOWER_BOUND, double UPPER_BOUND, unsigned int SEED) :
            Distribution(SEED),
            LOWER_BOUND{LOWER_BOUND},
            UPPER_BOUND{UPPER_BOUND},
            realDistribution(LOWER_BOUND, UPPER_BOUND) {}

    /** Returns a double randomly generated between the two bounds, based on the internal seed of the distribution */
    double rand() {return realDistribution(mt);}
};


#endif //EVE_UNIFORM_H
