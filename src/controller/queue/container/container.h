#ifndef EVE_CONTAINER_H
#define EVE_CONTAINER_H

#include "container_e.h"

template <class T>
struct Container : Container_e {
    const T & item;

    explicit Container(const T & item) :
        item{item} {}
    Container(const T & item, Container * prev, Container * next) :
        Container_e(prev, next),
        item{item} {}
};

#endif //EVE_CONTAINER_H
