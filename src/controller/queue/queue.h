//
// Created by aaron on 09/10/2019.
//

#ifndef EVE_QUEUE_H
#define EVE_QUEUE_H

#include "container/container.h"
#include "../thread_handler/task/task.h"

template <class T>
class Queue {
    Container<T> * back = nullptr;
    Container<T> * front = nullptr;
public:
    virtual void push(const Task_e & task);
    virtual Task_e pop();
    virtual int size();
    virtual bool empty();
};

#endif //EVE_QUEUE_H
