//
// Created by aaron on 11/10/2019.
//

#include "container.h"

Container::Container() : Container(nullptr, nullptr) {}
Container::Container(Container * prev, Container * next) {}

Container::~Container() {
    delete prev;
    delete next;
}
