#ifndef EVE_GLUTTONY_H
#define EVE_GLUTTONY_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

#define GLUTTONY_TURN_WEIGHT        0.4
#define GLUTTONY_CHANGE_DIR_WEIGHT  0.01

class Gluttony : public Brain {
    bool turnLeft = true;

public:
    const brain::Nature nature = brain::GLUTTONY;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles, double energy) override;
};


#endif //EVE_GLUTTONY_H

