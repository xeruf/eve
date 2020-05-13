#ifndef EVE_WRATH_H
#define EVE_WRATH_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

class Wrath : public Brain {
public:
    const brain::Nature nature = brain::WRATH;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles, Individual const * body) override;
};


#endif //EVE_WRATH_H

