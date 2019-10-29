#ifndef EVE_INDIVIDUAL_H
#define EVE_INDIVIDUAL_H

#include "../entity.h"
#include "../../../action/action.h"

class Individual : public Entity {
private:
    static int numberOfIndividuals;
    const int ID;
    const int visionRange = 15;
public:
    Individual(int x, int y, int energy);
    ~Individual() override = 0;

    int getID();
    int getVisionRange();

    Action * act(std::vector<Object *> * visibles);
};

#endif //EVE_INDIVIDUAL_H
