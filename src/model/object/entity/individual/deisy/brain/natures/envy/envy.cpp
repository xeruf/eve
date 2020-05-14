#include "envy.h"

Envy::Envy (Individual const * body) : Brain (body) {}

Action Envy::think (const std::unique_ptr <std::vector <Object *>> & visibles) {
    return Action ((action) Uniform (1, 5).rand());
}

