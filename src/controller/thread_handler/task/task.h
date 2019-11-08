//
// Created by aaron on 11/10/2019.
//

#ifndef EVE_TASK_H
#define EVE_TASK_H

#include "../../future/future.h"

#include <functional>

struct Task_e {virtual void run() {};};

template <class R, class... Args>
struct Task : Task_e {
    Future<R> future;
    bool done = false;

    void run(std::function<R(Args... args)> f);
};

#endif //EVE_TASK_H
