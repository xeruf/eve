#include <textstyle.h>
#include "piercy.h"

Piercy::Piercy(double x, double y, double energy) : Individual(x, y, energy) {}

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