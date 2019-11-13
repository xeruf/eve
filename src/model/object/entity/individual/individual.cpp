#include "individual.h"

long Individual::numberOfIndividuals = 0;

Individual::Individual(double x, double y, double angle, double energy) :
    Individual(x, y, Vector(angle, VISION_RANGE), energy) {}

Individual::Individual(double x, double y, Vector vision, double energy) :
    Entity(x, y, energy),
    vision{vision},
    ID{numberOfIndividuals++}
{}

Individual::~Individual() = default;

long Individual::getID() const {return ID;}

Vector Individual::getVision() const {return vision;}

