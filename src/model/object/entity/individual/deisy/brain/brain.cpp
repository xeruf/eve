#include "brain.h"

Brain::Brain (Individual const * body) : body {body} {}

Uniform Brain::dice = Uniform {0, 1};


/* Copyright (C) 2020 Aaron Alef & Felix Bachstein */