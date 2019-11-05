#include "individual.h"

long Individual::numberOfIndividuals = 0;
Individual::Individual(double x, double y, double energy) :
    Entity(x, y, energy),
    ID(numberOfIndividuals)
{numberOfIndividuals++;}

Individual::~Individual() = default;

long Individual::getID() {return ID;}

double Individual::getVisionRange() { return visionRange;}
