#ifndef EVE_INDIVIDUAL_H
#define EVE_INDIVIDUAL_H

#include "../entity.h"

#include "../../../../config.h"
#include "../../../model.h"
#include "../../../action/action.h"

class Individual : public Entity {
private:
    Individual(double x, double y, Vector vision, double energy);

    static long numberOfIndividuals;
    const long ID;

    Vector vision;

public:
    Individual(double x, double y, double angle, double energy);
    ~Individual() override = 0;

    [[nodiscard]] long getID() const;
    [[nodiscard]] Vector getVision() const;

    virtual Action * act(std::vector<Object *> * visibles) = 0;
};

#endif //EVE_INDIVIDUAL_H
