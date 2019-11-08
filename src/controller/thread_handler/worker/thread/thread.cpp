#include "thread.h"

Thread::Thread(Queue<Task_e> & queue) : queue{queue}, thread(* this) {}
Thread::Thread(Thread && other) noexcept : queue(other.queue) {}
Thread::~Thread() {
    stopThread = true;
    thread.join();
}
void Thread::operator () () {
    while (not stopThread) queue.pop()();
}