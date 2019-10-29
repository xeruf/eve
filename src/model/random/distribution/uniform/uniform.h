#ifndef EVE_UNIFORM_H
#define EVE_UNIFORM_H

#include "../distribution.h"

struct Uniform : Distribution {
    std::uniform_real_distribution<double> realDistribution;

    const double LOWER_BOUND;
    const double UPPER_BOUND;

    Uniform(double LOWER_BOUND, double UPPER_BOUND) :
            Uniform(LOWER_BOUND, UPPER_BOUND, generateSeed()) {}

    Uniform(double LOWER_BOUND, double UPPER_BOUND, unsigned int SEED) :
            Distribution(SEED),
            LOWER_BOUND{LOWER_BOUND},
            UPPER_BOUND{UPPER_BOUND},
            realDistribution(LOWER_BOUND, UPPER_BOUND)
    {}

    double rand() {return realDistribution(mt);}
};


#endif //EVE_UNIFORM_H
