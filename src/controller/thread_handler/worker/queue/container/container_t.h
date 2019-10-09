//
// Created by aaron on 11/10/2019.
//

#ifndef EVE_CONTAINER_T_H
#define EVE_CONTAINER_T_H

#include "container.h"

template <class T>
struct Container_T : Container {
    T & item;
};

#endif //EVE_CONTAINER_T_H
