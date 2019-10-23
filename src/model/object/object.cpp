#include "object.h"

Object::Object(int x, int y) : position{x, y} {}

Point Object::getPosition() {return position;}