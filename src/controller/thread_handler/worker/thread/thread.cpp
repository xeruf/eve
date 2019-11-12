#include "thread.h"

Thread::Thread(Queue<Task_e> & queue) :
    queue{queue},
    thread(& Thread::run, this) {
        std::cout << "Start\t" <<  this << " (" << (unsigned long) this % 128 << ")" << std::endl;
    }
Thread::Thread(Thread && other) noexcept :
    queue{other.queue},
    thread{std::move(thread)} {
        std::cout << "Move\t" <<  this << " (" << (unsigned long) this % 128 << ") \t(from " << & other << ")" << std::endl;
    }
Thread::~Thread() {
    stopThread = true;
    if (thread.joinable()) join();

    std::cout << "Join\t" <<  this << " (" << (unsigned long) this % 128 << ")" << std::endl;
}

void Thread::join () {
    std::cout << "Stop\t" <<  this << " (" << (unsigned long) this % 128 << ")" << std::endl;

    thread.join();
}

void Thread::run () {
    std::cout << "Run \t" <<  this << " (" << (unsigned long) this % 128 << ")" << std::endl;

    while (not stopThread) queue.pop()();
}