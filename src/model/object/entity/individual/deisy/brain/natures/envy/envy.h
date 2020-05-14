#ifndef EVE_ENVY_H
#define EVE_ENVY_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../algebra/algebra.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

class Envy : public Brain {
public:
    explicit Envy (Individual const * body);

    const brain::Nature nature = brain::ENVY;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles) override;
};


#endif //EVE_ENVY_H

