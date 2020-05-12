#ifndef EVE_GLUTTONY_H
#define EVE_GLUTTONY_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

class Gluttony : public Brain {
public:
    const brain::Nature nature = brain::GLUTTONY;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles, double energy) override;
};


#endif //EVE_GLUTTONY_H

