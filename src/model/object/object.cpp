//
// Created by aaron on 26/09/2019.
//

#include "object.h"

Object::Object(Point position) : position{position} {}
Object::Object(int x, int y) : position{x, y} {}

Point Object::getPosition() {return position;}
void Object::setPosition(Point p) {position = p;}
void Object::setPosition(int x, int y) {position = Point(x, y);}