#include "entity.h"

Entity::Entity(double x, double y, double energy) :
    Entity(Point(x, y), energy) {}

Entity::Entity(Point position, double energy) :
    Object(position),
    energy{energy} {checkEnergy();}

void Entity::checkEnergy() const {
    if (energy <= 0) throw std::range_error("Entity::checkEnergy(): Energy has to be positive");
}

double Entity::getEnergy() const {return energy;}

void Entity::setPosition(Point p) { position = p;}
void Entity::setPosition(double x, double y) { position = Point(x, y);}

double Entity::getRadius() const { return sqrt(energy) / M_PI; }

const Vector & Entity::applyForce(const Vector & v) {
    return speed += v;
}

const Vector & Entity::applyFriction() {
    return speed = Vector(speed.angle, 0.5 * speed.length);
}

Point Entity::updatePosition() {
    return position += speed;
}
Point Entity::updatePosition(const std::function<Point(Point)> & normalise) {
    return position = normalise(position + speed);
}

double Entity::updateEnergy (double multiplier) {
    return energy *= multiplier;
}

double Entity::addEnergy (double energy) {
    return energy += energy;
}