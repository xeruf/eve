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

void ThreadHandler::async(Task_e & task, int priority) {
    int index = std::max(0, std::min(threadAmount, priority));
    workers[index].push(task);
}