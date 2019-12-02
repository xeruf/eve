#ifndef EVE_INDIVIDUAL_H
#define EVE_INDIVIDUAL_H

#include "../entity.h"

#include "../../../../config.h"
#include "../../../algebra/algebra.h"
#include "../../../action/action.h"

#include <memory>

class Individual : public Entity {
private:
    Individual(long ID, Point position, Vector vision, double energy);

    const long ID;

    Vector vision;

public:
    Individual(long ID, double x, double y, double angle, double energy);
    Individual(long ID, Point position, double angle, double energy);
    ~Individual() override = 0;

    [[nodiscard]] long getID() const;
    [[nodiscard]] Vector getVision() const;

    virtual Action act(const std::unique_ptr<std::vector<Object *>> & visibles) = 0;
};

#endif //EVE_INDIVIDUAL_H
