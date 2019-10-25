#include "action.h"

Sleep::Action::~Action() = default;

Sleep::~Sleep() {
    Action::~Action();
}
