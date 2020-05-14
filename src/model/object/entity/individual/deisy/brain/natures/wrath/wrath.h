#ifndef EVE_WRATH_H
#define EVE_WRATH_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../algebra/algebra.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

#define WRATH_MOVE_WEIGHT 0.8
#define WRATH_TURN_WEIGHT 0.8
#define WRATH_REPRODUCTION_MODIFIER 1.2

class Wrath : public Brain {
    int visiblesLimit = int (std::floor (dice.rand() * 4 + 1));
    bool turnLeft = bool (std::round (dice.rand()));

public:
    explicit Wrath (Individual const * body);

    const brain::Nature nature = brain::WRATH;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles) override;
};


#endif //EVE_WRATH_H

