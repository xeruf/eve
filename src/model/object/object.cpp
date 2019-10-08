//
// Created by aaron on 26/09/2019.
//

#include "object.h"

Object::Object(int x, int y) : position{x, y} {}

Point Object::getPosition() {return position;}