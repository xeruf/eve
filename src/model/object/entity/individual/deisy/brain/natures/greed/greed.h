#ifndef EVE_GREED_H
#define EVE_GREED_H

#include "../../brain.h"
#include "../../../../../../../../config.h"
#include "../../../../../../../action/action.h"
#include "../../../../../../../random/random.h"

#include <vector>
#include <memory>

#define GREED_SIDE_AREA 0.35
#define GREED_REPRODUCTION_THRESHOLD_MULTIPLIER 1.5

class Greed : public Brain {
    const Angle sideAngle = Angle (MOUTH_ANGLE) * GREED_SIDE_AREA;
    const Angle middleAngle = Angle (MOUTH_ANGLE) * (1 - 2 * GREED_SIDE_AREA);

public:
    explicit Greed (Individual const * body);

    const brain::Nature nature = brain::GREED;

    Action think (const std::unique_ptr <std::vector <Object *>> & visibles) override;
};


#endif //EVE_GREED_H

