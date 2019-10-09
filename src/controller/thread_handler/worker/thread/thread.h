//
// Created by aaron on 09/10/2019.
//

#ifndef EVE_THREAD_H
#define EVE_THREAD_H

#include "../queue/queue.h"
#include "../queue/container/container.h"
#include "../queue/container/task.h"

#include <utility>
#include <thread>
#include <functional>

class Thread {
private:
    std::function<Container()> pop;
    std::thread thread;
    bool stopThread = false;

    void run();
public:
    explicit Thread(const std::function<Container()> & pop);
    ~Thread();
};


#endif //EVE_THREAD_H
