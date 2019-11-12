#ifndef EVE_THREAD_H
#define EVE_THREAD_H

#include "../../../queue/queue.h"
#include "../../../task/task.h"

#include <utility>
#include <thread>
#include <functional>

class Thread {
private:
    Queue<Task_e> & queue;
    std::thread thread;
    volatile bool stopThread = false;

public:
    explicit Thread(Queue<Task_e> & queue);
    Thread(Thread && other) noexcept;
    ~Thread();

    void run();
};


#endif //EVE_THREAD_H
