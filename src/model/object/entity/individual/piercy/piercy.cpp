#include "piercy.h"

Piercy::Piercy(double x, double y, double energy) : Individual(x, y, energy) {}

Action * Piercy::act(std::vector<Object *> * visibles) {
    while (true) {
        std::cin.ignore(10000, '\n');
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