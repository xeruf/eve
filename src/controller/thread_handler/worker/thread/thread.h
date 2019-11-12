#ifndef EVE_THREAD_H
#define EVE_THREAD_H

#include "../../../queue/queue.h"
#include "../../../task/task.h"

#include <utility>
#include <thread>
#include <functional>

#include <iostream>

class Thread {
private:
    Queue<Task_e> & queue;
    std::thread thread;
    bool stopThread = false;

    void join();

public:
    explicit Thread(Queue<Task_e> & queue);
    Thread(Thread && other) noexcept;
    ~Thread();

    void run();
};


#endif //EVE_THREAD_H
