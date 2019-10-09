//
// Created by aaron on 09/10/2019.
//

#ifndef EVE_THREAD_HANDLER_H
#define EVE_THREAD_HANDLER_H

#define DEFAULT_THREADS 1

#include "worker/worker.h"

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
};


#endif //EVE_THREAD_HANDLER_H
