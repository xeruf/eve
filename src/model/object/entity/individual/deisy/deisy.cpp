#include "deisy.h"

Deisy::Deisy(long ID, Point position, double a, double energy) :
    Deisy(ID, position, a, energy, DEFAULT_COLOR) {}

Deisy::Deisy(long ID, Point position, double a, double energy, int color) :
    Deisy(ID, position, a, energy, color, (brain::Nature) std::floor (NatureDist.rand())) {}

Deisy::Deisy(long ID, Point position, double a, double energy, int color, brain::Nature nature) :
    Individual(ID, position, a, energy, COLOR_BY_NATURE ? brain::Color [nature] : color),
    brain {[nature]() -> Brain * {
        switch (nature) {
            case brain::LUST:
                return new Lust;
            case brain::GLUTTONY:
                return new Gluttony;
            case brain::GREED:
                return new Greed;
            case brain::SLOTH:
                return new Sloth;
            case brain::WRATH:
                return new Wrath;
            case brain::ENVY:
                return new Envy;
            case brain::PRIDE:
                return new Pride;
        }
    }()} {}

Deisy * Deisy::reproduce(unsigned long ID) {
    return new Deisy (static_cast<long>(ID), position, getVision().angle.radians(), reproductionSplit(), darken (color), brain->nature);
}

Action Deisy::act(const std::unique_ptr<std::vector<Object *>> & visibles) {
    brain->think (visibles);
}

int Deisy::getColor() const {
    return color;
}
