#ifndef EVE_PIERCY_H
#define EVE_FRED_H

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"

class Fred : public Individual {
public:
    Fred(double x, double y, double a, double energy);
  
    Action * act(std::vector<Object *> * visibles) override;
};

#endif //EVE_PIERCY_H
