#include "individual.h"

long Individual::numberOfIndividuals = 0;
Individual::Individual(double x, double y, double a, double energy) :
    Entity(x, y, energy),
    direction{a},
    ID{numberOfIndividuals++}
{}

Individual::~Individual() = default;

Individual::~Individual() = default;

long Individual::getID() {return ID;}

double Individual::getDirection() {return direction;}

double Individual::getVisionRange() { return visionRange;}
