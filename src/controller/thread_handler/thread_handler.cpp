#include "thread_handler.h"

int ThreadHandler::threadAmount = DEFAULT_THREADS;

ThreadHandler::ThreadHandler() : ThreadHandler(calcThreadAmount()) {}
ThreadHandler::ThreadHandler(int threads) {
    threadAmount = threads;
    for (int i = 0; i < threads; i++) workers.emplace_back();
    workers.shrink_to_fit();
}
int ThreadHandler::calcThreadAmount() {
    int threadsSupported = (int) std::thread::hardware_concurrency();
    if (threadsSupported) threadAmount = threadsSupported;
    return threadAmount;
}

int ThreadHandler::getThreadAmount() {return threadAmount;}

void ThreadHandler::schedule (Task_e & task, Priority priority) {
    int index = std::max(0, std::min<int>(threadAmount, priority));
    workers[index].push(task);
}

void async (Task_e & task) {
    ThreadHandler::schedule(task);
}