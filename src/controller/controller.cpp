//
// Created by aaron on 27/09/2019.
//

#include "controller.h"

Controller::Controller(int WIDTH, int HEIGHT, int ENERGY) :
    world(World(WIDTH, HEIGHT, ENERGY)) {}

int Controller::run() {
    while (simulate()) iteration++;
    return iteration;
}

bool Controller::simulate() {
    // TODO What has to be simulated
    return false;
}