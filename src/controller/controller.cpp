#include "controller.h"

Controller::Controller(int WIDTH, int HEIGHT, int ENERGY) :
    world(World(WIDTH, HEIGHT, ENERGY))
{}

void Controller::init() {
    for (int i = 0; i < 10; i++) world.addIndividual(new Fred(10 * i, 10 * i, 40));
    world.fillWithFood([](World * w) -> Food * {
        return new Food(
                std::experimental::randint(0, w->WIDTH),
                std::experimental::randint(0, w->HEIGHT),
                (w->ENERGY - w->getEnergy()) < MAX_FOOD_SIZE ? w->ENERGY - w->getEnergy() : std::experimental::randint(1, MAX_FOOD_SIZE));
    });

    initialised = true;
}

int Controller::run() {
    if (not initialised) throw(std::logic_error("Controller::run(): .init() must be run first"));
    while (simulate()) iteration++;
    return iteration;
}

bool Controller::simulate() {
    terminalview.render(world);
    for (auto individual : world.getIndividuals()) {
        auto visibles = world.getObjectsAround(individual->getPosition(), individual->getVisionRange());
        auto action = individual->act(visibles);
        std::cout << action->toString() << std::endl;
        delete action;
        delete visibles;
    }
    world.kill(iteration);
    return not world.getIndividuals().empty();
}