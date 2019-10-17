//
// Created by aaron on 27/09/2019.
//

#include "controller.h"

Controller::Controller(int WIDTH, int HEIGHT, int ENERGY) :
    world(World(WIDTH, HEIGHT, ENERGY))
{}

void Controller::init() {
    initialised = true;
}

int Controller::run() {
    if (not initialised) throw(std::logic_error("Controller::run(): .init() must be run first"));
    while (simulate()) iteration++;
    return iteration;
}

bool Controller::simulate() {
    // TODO What has to be simulated
    return false;
}