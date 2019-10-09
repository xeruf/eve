//
// Created by aaron on 09/10/2019.
//

#ifndef EVE_WORKER_H
#define EVE_WORKER_H

#include "queue/queue.h"
#include "queue/container/container.h"
#include "thread/thread.h"

class Worker : private Queue<Container> {
private:
    Thread thread;
public:
    Worker();
};


#endif //EVE_WORKER_H
