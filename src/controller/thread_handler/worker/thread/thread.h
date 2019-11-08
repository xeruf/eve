#ifndef EVE_THREAD_H
#define EVE_THREAD_H

#include "../../../queue/queue.h"
#include "../../task/task.h"

#include <utility>
#include <thread>
#include <functional>

class Thread {
private:
    Queue<Container<Task_e>> & queue;
    std::thread thread;
    volatile bool stopThread = false;

    void run();
public:
    explicit Thread(Queue<Container<Task_e>> & queue);
    Thread(Thread && other) noexcept;
    ~Thread();
};


#endif //EVE_THREAD_H
