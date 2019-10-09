//
// Created by aaron on 11/10/2019.
//

#ifndef EVE_TASK_H
#define EVE_TASK_H

#include "container_t.h"

#include <functional>

template <class Future, class... Args>
struct Task : Container_T<std::function<Future(Args...)>> {
    Future * future;
    bool done = false;

    void run(Args... args);
};

#endif //EVE_TASK_H
