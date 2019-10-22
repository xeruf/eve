#include "fred.h"

Fred::Fred(int x, int y, int energy) : Individual(x, y, energy) {}

Fred::Individual::~Individual() = default;

void Fred::act() {}