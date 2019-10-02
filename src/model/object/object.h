//
// Created by aaron on 01/10/2019.
//

#ifndef EVE_OBJECT_H
#define EVE_OBJECT_H

#include "../geometry/shape/shape.h"

#include <vector>

class Object {
public:
    virtual Shape getHitBox() = 0;
};


#endif //EVE_OBJECT_H
