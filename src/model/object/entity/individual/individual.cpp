#include "individual.h"


Individual::Individual(long ID, Point position, double angle, double energy, int color) :
        Individual(ID, position, Vector(angle, VISION_RANGE), energy, color) {}

Individual::Individual(long ID, Point position, double angle, double energy) :
    Individual(ID, position, Vector(angle, VISION_RANGE), energy, DEFAULT_COLOR) {}

Individual::Individual(long ID, Point position, Vector vision, double energy, int color) :
    Entity(position, energy),
    vision{vision},
    ID{ID},
    color {color} {}

Individual::~Individual() = default;

long Individual::getID() const {return ID;}

Vector Individual::getVision() const {return vision;}

void Individual::turnBy(Angle angle) {
    vision += angle;
}

double Individual::eat (const Food & food) {
    return addEnergy (food.getEnergy());
}

int Individual::getColor() {
    return color;
}

double Individual::reproductionSplit() {
    double childEnergy = getEnergy() * REPRODUCTION_CHILD_FRACTION;
    updateEnergy(getEnergy() - childEnergy);
    return childEnergy;
}
