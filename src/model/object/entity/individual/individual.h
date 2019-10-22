#ifndef EVE_INDIVIDUAL_H
#define EVE_INDIVIDUAL_H

#include "../entity.h"

class Individual : public Entity {
private:
    static int numberOfIndividuals;
    const int ID;
public:
    Individual(int x, int y, int energy);
    ~Individual() override = 0;

    int getID();
};

#endif //EVE_INDIVIDUAL_H
