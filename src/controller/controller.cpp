#include "controller.h"

Controller::Controller(double WIDTH, double HEIGHT, double ENERGY) :
    world(World(WIDTH, HEIGHT, ENERGY))
{}

void Controller::init() {
    static Uniform distX = Uniform(0.0, world.WIDTH);
    static Uniform distY = Uniform(0.0, world.HEIGHT);
    static Uniform distE = Uniform(MIN_FOOD_SIZE, MAX_FOOD_SIZE);

    for (int i = 0; i < AMOUNT_OF_FREDS; i++) {
        world.addIndividual(new Fred(0 + i, 0 + i, 0, 0.2 * world.ENERGY));
    }

    for (int i = 0; i < AMOUNT_OF_PIERCIES; i++) {
        world.addIndividual(new Piercy(0 - i, 0 - i, 0, 0.2 * world.ENERGY));
    }
  
    world.fillWithFood([](World * w) -> Food * {
        return new Food(
                distX.rand(),
                distY.rand(),
                (w->ENERGY - w->getEnergy()) < MAX_FOOD_SIZE ? w->ENERGY - w->getEnergy() : distE.rand());
    });

    initialised = true;
}

long Controller::run() {
    if (not initialised) throw(std::logic_error("Controller::run(): .init() must be run first"));
    while (simulate()) iteration++;
    return iteration;
}

bool Controller::simulate() {
    if (RENDER_TERMINALVIEW) terminalview.render(world);

    for (auto individual : world.getIndividuals()) {

        auto visibles = world.getObjectsAround(individual->getPosition(), individual->getVisionRange());
        auto action = individual->act(visibles);
        std::cout << action->toString() << std::endl;
        delete action;
        delete visibles;
    }
    return not world.getIndividuals().empty();
}