#include "worker.h"

Worker::Worker() : Queue<Task_e>(), thread{* this} {}
Worker::Worker(Worker && other) noexcept : thread{std::move(other.thread)} {}
