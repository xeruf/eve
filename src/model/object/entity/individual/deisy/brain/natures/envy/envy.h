#ifndef EVE_ENVY_H
#define EVE_ENVY_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../algebra/algebra.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

#define ENVY_MOVE_WEIGHT 0.8
#define ENVY_TURN_WEIGHT 0.8

class Envy : public Brain {
    int visiblesLimit = int (std::floor (dice.rand() * 4 + 1));
    bool turnLeft = bool (std::round (dice.rand()));

public:
    explicit Envy (Individual const * body);

    const brain::Nature nature = brain::ENVY;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles) override;
};


#endif //EVE_ENVY_H

