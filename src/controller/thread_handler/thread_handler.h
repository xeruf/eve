#ifndef EVE_THREAD_HANDLER_H
#define EVE_THREAD_HANDLER_H

#include "worker/worker.h"
#include "../task/task.h"
#include "../../config.h"

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
    static std::vector<Worker> workers;
    static int threadAmount;

    static int calcThreadAmount();

public:
    ThreadHandler();
    explicit ThreadHandler(int threads);

    static int getThreadAmount();

    static void schedule (Task_e & task, Priority priority = DEFAULT);
};

void async (Task_e & task);

#endif //EVE_THREAD_HANDLER_H
