//
// Created by aaron on 09/10/2019.
//

#ifndef EVE_WORKER_H
#define EVE_WORKER_H

#include "../../queue/queue.h"
#include "thread/thread.h"
#include "../task/task.h"

class Worker : public Queue<Container<Task_e>> {
private:
    Thread thread;
public:
    Worker();
};


#endif //EVE_WORKER_H
