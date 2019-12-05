#ifndef EVE_VIEW_H
#define EVE_VIEW_H

#include "../model/world/world.h"

struct View {
    virtual void init(const World & world) = 0;
    virtual void stop() = 0;
};

#endif //EVE_VIEW_H
