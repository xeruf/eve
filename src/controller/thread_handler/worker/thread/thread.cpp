#include "thread.h"

Thread::Thread(const Queue<Container<Task_e>> * queue) : queue{queue} {}
Thread::~Thread() {
    stopThread = true;
    thread.join();
}

void Thread::run() {
    while (not stopThread) queue.pop().run();
}