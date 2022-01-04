#ifndef EVE_SLOTH_H
#define EVE_SLOTH_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

#define SLOTH_MOVE_WEIGHT 0.01
#define SLOTH_TURN_WEIGHT 0.05
#define SLOTH_CHANGE_DIR  0.02

class Sloth : public Brain {
    bool turnLeft = bool (std::round (dice.rand()));

public:
    explicit Sloth (Individual const * body);

    const brain::Nature nature = brain::SLOTH;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles) override;
};


#endif //EVE_SLOTH_H

