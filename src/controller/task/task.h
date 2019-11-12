#ifndef EVE_TASK_H
#define EVE_TASK_H

#include <functional>

struct Task_e {
    virtual void operator () () {}
};

template <class R, class... Args>
class Task : Task_e {
    std::function<R(Args... args)> f;

public:
    explicit Task(std::function<R(Args... args)> f) : f{f} {};


    void operator () () override {
        f();
    }
};

#endif //EVE_TASK_H
