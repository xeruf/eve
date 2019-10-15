//
// Created by aaron on 11/10/2019.
//

#ifndef EVE_CONTAINER_H
#define EVE_CONTAINER_H

#include "container_e.h"

template <class T>
struct Container : Container_e {
    T & item;
};

#endif //EVE_CONTAINER_H
