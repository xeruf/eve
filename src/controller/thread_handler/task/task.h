#ifndef EVE_TASK_H
#define EVE_TASK_H

#include "../../promise/promise.h"

#include <functional>

struct Task_e {
    virtual void operator () () {}
    virtual void * promise() {return nullptr;}
};

template <class R, class... Args>
class Task : Task_e {
    std::function<R(Args... args)> f;
    Promise<R> * val = new Promise<R>();

public:
    explicit Task(std::function<R(Args... args)> f);

    Promise<R> * promise() override;

    void operator () ();
};

#endif //EVE_TASK_H
