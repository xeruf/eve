#ifndef EVE_WORKER_H
#define EVE_WORKER_H

#include "../../queue/queue.h"
#include "thread/thread.h"
#include "../task/task.h"

class Worker : public Queue<Task_e> {
private:
    Thread thread;
public:
    Worker();
    Worker(Worker && other) noexcept;
    
};


#endif //EVE_WORKER_H
