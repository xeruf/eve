//
// Created by aaron on 11/10/2019.
//

#include "task.h"

template <class R, class... Args>
void Task<R, Args...>::run(std::function<R(Args... args)> f) {
    * future = f();
    done = true;
}
