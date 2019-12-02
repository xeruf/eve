#include "piercy.h"

Piercy::Piercy(long ID, double x, double y, double a, double energy) :
        Individual(ID, x, y, a, energy) {}

Piercy::Piercy(long ID, Point position, double a, double energy) :
    Individual(ID, position, a, energy) {}

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