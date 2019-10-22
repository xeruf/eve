#ifndef EVE_FRED_H
#define EVE_FRED_H

#include "../individual.h"

class Fred : public Individual {
public:
    Fred(int x, int y, int energy);

    void act();
};

#endif //EVE_FRED_H
