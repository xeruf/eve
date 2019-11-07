#include "object.h"

Object::Object(double x, double y) : position{x, y} {}

Point Object::getPosition() const {return position;}