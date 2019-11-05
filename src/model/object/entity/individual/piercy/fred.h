#ifndef EVE_FRED_H
#define EVE_FRED_H

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"

class Piercy : public Individual {
public:
    Piercy(double x, double y, double energy);
  
    Action * act(std::vector<Object *> * visibles);
};

#endif //EVE_FRED_H
