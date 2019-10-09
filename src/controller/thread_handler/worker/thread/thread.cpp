//
// Created by aaron on 09/10/2019.
//

#include "thread.h"

Thread::Thread(const std::function<Container()> & pop) : pop{pop}, thread{std::thread(& Thread::run)} {}
Thread::~Thread() {
    stopThread = true;
    thread.join();
}

void Thread::run() {
    while (not stopThread) {
        pop().run();
    }
}