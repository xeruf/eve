#ifndef EVE_FUTURE_H
#define EVE_FUTURE_H

#include "../promise/promise.h"
#include "../task/task.h"

template <class R>
class Future {
private:
    const Promise<R> * val;
    const volatile bool & done = val->isDone();

public:
    explicit Future(const Promise<R> * promise);
    ~Future();

    [[nodiscard]] bool isDone() const;
    R await();
};


#endif //EVE_FUTURE_H
