#ifndef EVE_LUST_H
#define EVE_LUST_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

#define LUST_MOVE_WEIGHT 0.8
#define LUST_TURN_WEIGHT 0.8

class Lust : public Brain {
    int visiblesLimit = int (std::floor (dice.rand() * 4 + 1));
    bool turnLeft = bool (std::round (dice.rand()));

public:
    const brain::Nature nature = brain::LUST;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles, double energy) override;

};


#endif //EVE_LUST_H

