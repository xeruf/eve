#ifndef EVE_PROMISE_H
#define EVE_PROMISE_H

template <class R>
class Promise {
private:
    R val;
    bool done = false;

public:
    [[nodiscard]] bool & isDone();
    R getValue() const;

    Promise<R> & operator = (const R & val);
};


#endif //EVE_PROMISE_H
