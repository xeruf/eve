//
// Created by aaron on 11/10/2019.
//

#include "task.h"

template <class Future, class... Args>
void Task<Future, Args...>::run(Args... args) {
    * future = item(args...);
    done = true;
}
