//
// Created by aaron on 09/10/2019.
//

#ifndef EVE_THREAD_H
#define EVE_THREAD_H

#include "../../../queue/queue.h"
#include "../../task/task.h"

#include <utility>
#include <thread>
#include <functional>

class Thread {
private:
    Queue<Container<Task_e>> * queue;
    std::thread thread;
    bool stopThread = false;

    void run();
public:
    explicit Thread(const Queue<Container<Task_e>> * queue);
    ~Thread();
};


#endif //EVE_THREAD_H
