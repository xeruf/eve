#include "individual.h"

long Individual::numberOfIndividuals = 0;
Individual::Individual(double x, double y, double energy) :
    Entity(x, y, energy),
    ID(numberOfIndividuals)
{numberOfIndividuals++;}

long Individual::getID() {return ID;}

int Individual::getVisionRange() { return visionRange;}
