#ifndef EVE_PRIDE_H
#define EVE_PRIDE_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

class Pride : public Brain {
public:
    const brain::Nature nature = brain::PRIDE;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles, Individual const * body) override;
};


#endif //EVE_PRIDE_H

