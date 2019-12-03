#include "object.h"

Object::Object (double x, double y) : Object (Point (x, y)) {}
Object::Object (Point position) : position{position} {}

Object::~Object() = default;

Point Object::getPosition() const {return position;}
