//
// Created by aaron on 11/10/2019.
//

#ifndef EVE_CONTAINER_H
#define EVE_CONTAINER_H

struct Container {
    Container * prev = nullptr;
    Container * next = nullptr;

    Container();
    Container(Container * prev, Container * next);
    ~Container();

    void run() {}
};


#endif //EVE_CONTAINER_H
