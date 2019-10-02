//
// Created by aaron on 26/09/2019.
//

#include "entity.h"

Entity::Entity(Point position) : position{position} {}
Entity::Entity(int x, int y) : position{x, y} {}

Point Entity::getPosition() {return position;}
void Entity::setPosition(Point p) { position = p;}
void Entity::setPosition(int x, int y) { position = Point(x, y);}