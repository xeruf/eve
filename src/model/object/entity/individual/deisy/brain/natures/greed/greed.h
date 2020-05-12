#ifndef EVE_GREED_H
#define EVE_GREED_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

class Greed : public Brain {
public:
    const brain::Nature nature = brain::GREED;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles, double energy) override;
};


#endif //EVE_GREED_H

