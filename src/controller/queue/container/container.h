#ifndef EVE_CONTAINER_H
#define EVE_CONTAINER_H

template <class T>
struct Container {
    Container<T> * prev = nullptr;
    Container<T> * next = nullptr;
    const T & item;

    explicit Container(const T & item, Container * prev = nullptr, Container * next = nullptr) :
        item{item},
        prev{prev},
        next{next} {}

    ~Container() {
        delete prev;
        delete next;
    }
};

#endif //EVE_CONTAINER_H
