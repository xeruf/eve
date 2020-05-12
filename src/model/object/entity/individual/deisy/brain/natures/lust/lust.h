#ifndef EVE_LUST_H
#define EVE_LUST_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

class Lust : public Brain {
public:
    const brain::Nature nature = brain::LUST;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles) override;

};


#endif //EVE_LUST_H

