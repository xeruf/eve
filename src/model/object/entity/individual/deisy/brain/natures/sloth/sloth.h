#ifndef EVE_SLOTH_H
#define EVE_SLOTH_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

class Sloth : public Brain {
public:
    const brain::Nature nature = brain::SLOTH;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles, double energy) override;
};


#endif //EVE_SLOTH_H

