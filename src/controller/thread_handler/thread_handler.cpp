//
// Created by aaron on 09/10/2019.
//

#include "thread_handler.h"

int ThreadHandler::threadAmount = DEFAULT_THREADS;

ThreadHandler::ThreadHandler() : ThreadHandler(calcThreadAmount()) {}
ThreadHandler::ThreadHandler(int threads) : workers{new Worker[threads]} {}

int ThreadHandler::calcThreadAmount() {
    int threadsSupported = (int) std::thread::hardware_concurrency();
    if (threadsSupported) threadAmount = threadsSupported;
    return threadAmount;
}

int ThreadHandler::getThreadAmount() {return threadAmount;}