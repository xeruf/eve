#include "promise.h"

template <class R>
bool & Promise<R>::isDone() {
    return done;
}

template <class R>
R Promise<R>::getValue() const {
    if (done) return val;
}

template <class R>
Promise<R> & Promise<R>::operator = (const R & val) {
    this->val = val;
    this->done = true;
    return * this;
}