#ifndef EVE_NORMAL_H
#define EVE_NORMAL_H

#include "../distribution.h"

template <typename T>
struct Normal : Distribution {
    std::normal_distribution<T> normalDistribution;

    Normal() : Normal(generateSeed()) {}
    Normal(unsigned int SEED) : Distribution(SEED), normalDistribution() {}

    T rand() {return normalDistribution(mt);}
};

#endif //EVE_NORMAL_H
