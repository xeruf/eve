#include "entity.h"

Entity::Entity(double x, double y, double energy) :
    Object(x, y),
    energy{energy}
{checkEnergy();}

void Entity::checkEnergy() {
    if (energy <= 0) throw std::range_error("Entity::checkEnergy(): Energy has to be positive");
}

double Entity::getEnergy() {return energy;}

void Entity::setPosition(Point p) { position = p;}
void Entity::setPosition(double x, double y) { position = Point(x, y);}

double Entity::getRadius() { return sqrt(energy) / M_PI; }

