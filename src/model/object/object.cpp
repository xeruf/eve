#include "object.h"

Object::Object(double x, double y) : position{x, y} {}

Object::~Object() = default;

Point Object::getPosition() const {return position;}
