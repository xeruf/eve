#ifndef EVE_THREAD_HANDLER_H
#define EVE_THREAD_HANDLER_H

#include "worker/worker.h"
#include "task/task.h"
#include "../../config.h"

#include <functional>
#include <cmath>
#include <thread>

class ThreadHandler {
private:
    Worker * workers;
    static int threadAmount;

    static int calcThreadAmount();
public:
    ThreadHandler();
    explicit ThreadHandler(int threads);

    static int getThreadAmount();

    void async(Task_e & task, int priority = 0);
};


#endif //EVE_THREAD_HANDLER_H
