#include "worker.h"

Worker::Worker() : Queue<Container<Task_e>>(), thread{* this} {}
Worker::Worker(Worker && other) noexcept : thread(std::move(other.thread)) {}