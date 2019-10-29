#ifndef EVE_FRED_H
#define EVE_FRED_H

#include "../individual.h"
#include "../../../object.h"
#include "../../../../action/action.h"

class Fred : public Individual {
public:
    Fred(int x, int y, int energy);

    Action * act(std::vector<Object *> * visibles);
};

#endif //EVE_FRED_H
