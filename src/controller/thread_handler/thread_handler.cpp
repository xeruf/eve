#include "thread_handler.h"

int ThreadHandler::threadAmount = DEFAULT_THREADS;

ThreadHandler::ThreadHandler() : ThreadHandler(calcThreadAmount()) {}
ThreadHandler::ThreadHandler(int threads) {
    std::cout << "init threadHandler\t";
    std::cout << threads << std::endl;

    threadAmount = threads;

    for (int i = 0; i < threads; i++) workers.emplace_back();
    workers.shrink_to_fit();
}
int ThreadHandler::calcThreadAmount() {
    int threadsSupported = ((int) std::thread::hardware_concurrency()) - 1;
    if (threadsSupported > 0) threadAmount = threadsSupported;
    return threadAmount;
}

int ThreadHandler::getThreadAmount() {return threadAmount;}

void ThreadHandler::schedule (Task_e & task, Priority priority) {
    int index = std::max(0, std::min<int>(threadAmount, priority));
    workers[index].push(task);
}
