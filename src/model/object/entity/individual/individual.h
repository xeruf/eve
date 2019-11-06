#ifndef EVE_INDIVIDUAL_H
#define EVE_INDIVIDUAL_H

#include "../entity.h"
#include "../../../action/action.h"

class Individual : public Entity {
private:
    static long numberOfIndividuals;
    const long ID;
    const double visionRange = 15;

    double direction;
public:
    Individual(double x, double y, double a, double energy);
    ~Individual() override = 0;

    long getID();
    double getDirection();
    double getVisionRange();

    virtual Action * act(std::vector<Object *> * visibles) = 0;
};

#endif //EVE_INDIVIDUAL_H
