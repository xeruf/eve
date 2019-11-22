#include "individual.h"

long Individual::numberOfIndividuals = 0;
Individual::Individual(double x, double y, double a, double energy) :
    Entity(x, y, energy),
    direction{a},
    ID{numberOfIndividuals++}
{}

Individual::~Individual() = default;

long Individual::getID() const {return ID;}

double Individual::getDirection() const {return direction;}

double Individual::getVisionRange() const {return visionRange;}
