#include "pride.h"

Action Pride::think (const std::unique_ptr <std::vector <Object *>> & visibles, Individual const * body) {
    return Action ((action) Uniform (1, 5).rand());
}

