#include "controller.h"

Controller::Controller(double WIDTH, double HEIGHT, double ENERGY) :
    world(World(WIDTH, HEIGHT, ENERGY))
{}

void Controller::init() {
    for (int i = 0; i < 10; i++) world.addIndividual(new Fred(10 * i, 10 * i, 40));
    world.fillWithFood([](World * w) -> Food * {
        return new Food(
                //TODO: Reintroduce randomness
                0,
                0,
                (w->ENERGY - w->getEnergy()) < MAX_FOOD_SIZE ? w->ENERGY - w->getEnergy() : MAX_FOOD_SIZE);
    });

    initialised = true;
}

long Controller::run() {
    if (not initialised) throw(std::logic_error("Controller::run(): .init() must be run first"));
    while (simulate()) iteration++;
    return iteration;
}

bool Controller::simulate() {
    for (auto individual : world.getIndividuals()) {
        auto action = individual->act(world.getObjectsAround(individual->getPosition(), individual->getVisionRange()));
        std::cout << typeid(action).name() << std::endl;
        delete action;
    }

    world.kill(iteration);
    return not world.getIndividuals().empty();
}