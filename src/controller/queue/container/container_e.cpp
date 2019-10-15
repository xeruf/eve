//
// Created by aaron on 11/10/2019.
//

#include "container_e.h"

Container_e::Container_e(Container_e * prev, Container_e * next) {}

Container_e::~Container_e() {
    delete prev;
    delete next;
}
