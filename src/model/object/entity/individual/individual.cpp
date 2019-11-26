#include "individual.h"


Individual::Individual(long ID, double x, double y, double angle, double energy) :
    Individual(ID, x, y, Vector(angle, VISION_RANGE), energy) {}

Individual::Individual(long ID, double x, double y, Vector vision, double energy) :
    ID{ID},
    Entity(x, y, energy),
    vision{vision} {}

Individual::~Individual() = default;

long Individual::getID() const {return ID;}

Vector Individual::getVision() const {return vision;}

