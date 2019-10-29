#include "action.h"

Action::Action(action type) : type{type} {}
Action::~Action() = default;

Eat::Eat() : Action(EAT) {}
std::string Eat::toString() {return std::string("eat");}

Move::Move() : Action(MOVE) {}
std::string Move::toString() {return std::string("move");}

Sleep::Sleep() : Action(SLEEP) {}
std::string Sleep::toString() {return std::string("sleep");}

