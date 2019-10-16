//
// Created by aaron on 26/09/2019.
//

#include "entity.h"

Entity::Entity(int x, int y, int energy) : Object(x, y), energy{energy} {checkEnergy();}

void Entity::checkEnergy() {
    if (energy <= 0) throw std::range_error("Energy has to be positive");
}

int Entity::getEnergy() {return energy;}

void Entity::setPosition(Point p) { position = p;}
void Entity::setPosition(int x, int y) { position = Point(x, y);}

Entity::Object::~Object() = default;