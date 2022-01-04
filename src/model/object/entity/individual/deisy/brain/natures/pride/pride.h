#ifndef EVE_PRIDE_H
#define EVE_PRIDE_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>
#include <cmath>
#include <stdexcept>

#define PRIDE_CHAIN_LENGTH 3
#define PRIDE_FLAT_BONUS 1.2

class Pride : public Brain {
    std::vector <std::pair <std::pair <int, double>, Action>> prevActions;
    std::size_t action_idx = 0;

    std::vector <std::vector <std::vector <std::vector <double>>>> weights;

    Action think();
    void update();

public:
    explicit Pride (Individual const * body);

    const brain::Nature nature = brain::PRIDE;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles) override;
};


#endif //EVE_PRIDE_H

