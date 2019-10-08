//
// Created by aaron on 27/09/2019.
//

#ifndef EVE_INDIVIDUAL_H
#define EVE_INDIVIDUAL_H

#include "../entity.h"

class Individual : public Entity {
private:
    const int ID;
public:
    Individual(int x, int y, int energy, int ID);
    virtual ~Individual() = 0;

    int getID();
};

#endif //EVE_INDIVIDUAL_H
