#include "piercy.h"

Piercy::Piercy(long ID, Point position, double a, double energy) :
        Individual(ID, position, a, energy, DEFAULT_COLOR) {}

Piercy::Piercy(long ID, Point position, double a, double energy, int color) :
    Individual(ID, position, a, energy, color) {}

Piercy * Piercy::reproduce(unsigned long ID) {
    return new Piercy (ID, position, getVision().angle.radians(), reproductionSplit(), darken (color));
}

Action Piercy::act(const std::unique_ptr<std::vector<Object *>> & visibles) {
    while (true) {
        std::cin.ignore(FLUSH_AMOUNT, '\n');
        switch (std::getchar()) {
            case 'm':
                return Action(MOVE);
            case 's':
                return Action(SLEEP);
        }
    }
}

int Piercy::getColor() {
    return color;
}
