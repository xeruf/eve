#ifndef EVE_NORMAL_H
#define EVE_NORMAL_H

#include "../distribution.h"

struct Normal : Distribution {
    std::normal_distribution<double> normalDistribution;

    Normal() : Normal(generateSeed()) {}
    Normal(unsigned int SEED) : Distribution(SEED), normalDistribution() {}

    double rand() {return normalDistribution(mt);}
};

#endif //EVE_NORMAL_H
