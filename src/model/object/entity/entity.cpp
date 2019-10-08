//
// Created by aaron on 26/09/2019.
//

#include "entity.h"

Entity::Entity(int x, int y) : Object(x, y) {}

void Entity::setPosition(Point p) { position = p;}
void Entity::setPosition(int x, int y) { position = Point(x, y);}