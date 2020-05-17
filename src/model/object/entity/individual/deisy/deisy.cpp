#include "deisy.h"

Deisy::Deisy(long ID, Point position, double a, double energy) :
    Deisy(ID, position, a, energy, DEFAULT_COLOR) {}

Deisy::Deisy(long ID, Point position, double a, double energy, int color) :
    Deisy(ID, position, a, energy, color, (brain::Nature) std::floor (NatureDist.rand())) {}

Deisy::Deisy(long ID, Point position, double a, double energy, int color, brain::Nature nature) :
        Deisy(ID, position, a, energy, COLOR_BY_NATURE ? brain::Color [nature] : color, nature, 0) {}

Deisy::Deisy(long ID, Point position, double a, double energy, int color, brain::Nature nature, int) :
    Individual(ID, position, a, energy, color),
    brain {[nature, this]() -> Brain * {
        switch (nature) {
            case brain::LUST:
                return new Lust (this);
            case brain::GLUTTONY:
                return new Gluttony (this);
            case brain::GREED:
                return new Greed (this);
            case brain::SLOTH:
                return new Sloth (this);
            case brain::WRATH:
                return new Wrath (this);
            case brain::ENVY:
                return new Envy (this);
            case brain::PRIDE:
                return new Pride (this);
            default:
                throw std::logic_error ("Deisy has gone insane - Insanity not yet implemented!");
        }
    }()} {}

Deisy * Deisy::reproduce(unsigned long ID) {
    return new Deisy (static_cast<long>(ID), position, getVision().angle.radians(), reproductionSplit(), darken (color), brain->nature, 0);
}

Action Deisy::act(const std::unique_ptr<std::vector<Object *>> & visibles) {
    return brain->think (visibles);
}

int Deisy::getColor() const {
    return color;
}
