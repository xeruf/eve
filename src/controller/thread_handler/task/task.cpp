#include "task.h"

template <class R, class... Args>
Task<R, Args...>::Task(std::function<R(Args... args)> f) : f{f} {}

template <class R, class... Args>
const Promise<R> * Task<R, Args...>::promise() {
    return val;
}

template <class R, class... Args>
void Task<R, Args...>::operator () () {
    * val = f();
}
