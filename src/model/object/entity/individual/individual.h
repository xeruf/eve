#ifndef EVE_INDIVIDUAL_H
#define EVE_INDIVIDUAL_H

#include "../entity.h"

#include "../../../../config.h"
#include "../../../algebra/algebra.h"
#include "../../../action/action.h"

class Individual : public Entity {
private:
    Individual(long ID, double x, double y, Vector vision, double energy);

    const long ID;

    Vector vision;

public:
    Individual(long ID, double x, double y, double angle, double energy);
    ~Individual() override = 0;

    [[nodiscard]] long getID() const;
    [[nodiscard]] Vector getVision() const;

    virtual Action * act(std::vector<Object *> * visibles) = 0;
};

#endif //EVE_INDIVIDUAL_H
