//
// Created by aaron on 27/09/2019.
//

#include "individual.h"

Individual::Individual(int x, int y, int energy, int ID) : Entity(x, y, energy), ID{ID} {}

int Individual::getID() {return ID;}