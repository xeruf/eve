#include "worker.h"

Worker::Worker() : Queue<Container<Task_e>>(), thread{* this} {}
