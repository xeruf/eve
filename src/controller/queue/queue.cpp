#include "queue.h"

template <class T>
void Queue<T>::push(const T & item) {}

template <class T>
T Queue<T>::pop() {}

template <class T>
int Queue<T>::size() const {
    return elements;
}

template <class T>
bool Queue<T>::empty() const {
    return !elements;
}

