#include "future.h"

template <class R>
Future<R>::Future(const Promise<R> * promise) : val{promise} {}

template <class R>
Future<R>::~Future() {
    delete val;
}

template <class R>
bool Future<R>::isDone() const {
    return done;
}

template <class R>
R Future<R>::await() {
    while (not done);
    return val->getValue();
}