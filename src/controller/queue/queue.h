#ifndef EVE_QUEUE_H
#define EVE_QUEUE_H

#include "container/container.h"
#include "../thread_handler/task/task.h"
#include "../promise/promise.h"

template <class T>
class Queue {
    Container<T> * back = nullptr;
    Container<T> * front = nullptr;

    int elements = 0;

public:
    virtual void * push(T item) {
        // LOCK HERE
        {
            Container<T> newItem(item, nullptr, back);
            back->prev = & newItem;
            back = & newItem;
        }
        return item.promise();
    }

    virtual T pop() {
        Container<T> * node;
        // LOCK HERE
        {
            node = front;
            front = front->prev;
            front->next = nullptr;
        }
        return node->item;
    }

    [[nodiscard]] virtual int size() const {
        return elements;
    }

    [[nodiscard]] virtual bool empty() const {
        return !elements;
    }
};

#endif //EVE_QUEUE_H
