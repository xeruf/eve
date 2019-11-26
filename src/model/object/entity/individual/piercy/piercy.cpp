#include "piercy.h"

Piercy::Piercy(long ID, double x, double y, double a, double energy) : Individual(ID, x, y, a, energy) {}

Action * Piercy::act(std::vector<Object *> * visibles) {
    while (true) {
        std::cin.ignore(FLUSH_AMOUNT, '\n');
        switch (std::getchar()) {
            case 'e':
                return new Eat();
            case 'm':
                return new Move();
            case 's':
                return new Sleep();
        }
    }
}