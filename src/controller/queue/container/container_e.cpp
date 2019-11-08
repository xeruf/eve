#include "container_e.h"

Container_e::Container_e(Container_e * prev, Container_e * next) {}

Container_e::~Container_e() {
    delete prev;
    delete next;
}
