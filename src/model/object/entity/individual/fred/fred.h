#ifndef EVE_FRED_H
#define EVE_FRED_H

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"

class Fred : public Individual {
public:
    Fred(long ID, double x, double y, double a, double energy);
    Fred(long ID, Point position, double a, double energy);

    Action act(const std::unique_ptr<std::vector<Object *>> & visibles) override;
};

#endif //EVE_FRED_H
