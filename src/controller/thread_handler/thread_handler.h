#ifndef EVE_THREAD_HANDLER_H
#define EVE_THREAD_HANDLER_H

#include "worker/worker.h"
#include "../task/task.h"
#include "../../config.h"

#include <iostream>

#include <functional>
#include <cmath>
#include <thread>
#include <vector>

enum Priority {
    DEFAULT,
    IMPORTANT,
    UI
};

class ThreadHandler {
private:
    std::vector<Worker> workers;
    static int threadAmount;

    static int calcThreadAmount();

public:
    ThreadHandler();
    explicit ThreadHandler(int threads);

    static int getThreadAmount();

    void schedule (Task_e & task, Priority priority = DEFAULT);
};

#endif //EVE_THREAD_HANDLER_H
