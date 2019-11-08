#ifndef EVE_QUEUE_H
#define EVE_QUEUE_H

#include "container/container.h"
#include "../thread_handler/task/task.h"

template <class T>
class Queue {
    Container<T> * back = nullptr;
    Container<T> * front = nullptr;

    int elements = 0;

public:
    virtual void push(const T & item) {}

    virtual T pop() {}

    [[nodiscard]] virtual int size() const {
        return elements;
    }

    [[nodiscard]] virtual bool empty() const {
        return !elements;
    }
};

#endif //EVE_QUEUE_H
