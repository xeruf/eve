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
    virtual void push(const Task_e & task);
    virtual Task_e pop() const;
    virtual int size() const;
    virtual bool empty() const;
};

#endif //EVE_QUEUE_H
