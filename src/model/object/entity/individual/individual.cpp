#include "individual.h"


Individual::Individual(long ID, double x, double y, double angle, double energy) :
        Individual(ID, Point(x, y), Vector(angle, VISION_RANGE), energy) {}

Individual::Individual(long ID, Point position, double angle, double energy) :
    Individual(ID, position, Vector(angle, VISION_RANGE), energy) {}

Individual::Individual(long ID, Point position, Vector vision, double energy) :
    Entity(position, energy),
    vision{vision},
    ID{ID} {}

Individual::~Individual() = default;

long Individual::getID() const {return ID;}

Vector Individual::getVision() const {return vision;}

void Individual::turnBy(Angle angle) {
    vision += angle;
}

double Individual::eat (const Food & food) {
    return addEnergy (food.getEnergy());
}
