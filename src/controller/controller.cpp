#include "controller.h"

Controller::Controller(double WIDTH, double HEIGHT, double ENERGY) :
    world(World(WIDTH, HEIGHT, ENERGY)) {
}

void Controller::init() {

    for (int i = 0; i < AMOUNT_OF_FREDS; i++) {
        world.addIndividual<Fred>(
                world.rand(X_d),
                world.rand(Y_d),
                world.rand(DIRECTION_d),
                world.rand(ENERGY_d));
    }

    for (int i = 0; i < AMOUNT_OF_PIERCIES; i++) {
        world.addIndividual<Piercy>(
                world.rand(X_d),
                world.rand(Y_d),
                world.rand(DIRECTION_d),
                world.rand(ENERGY_d));
    }

    world.setRefillFunction([](World * w) -> Food * {
        return new Food(
                w->rand(X_d),
                w->rand(Y_d),
                (w->ENERGY - w->getEnergy()) < MAX_FOOD_SIZE ?
                    w->ENERGY - w->getEnergy() :
                    w->rand(ENERGY_d));
    });

    initialised = true;
}

long Controller::run() {
    if (not initialised) throw(std::logic_error("Controller::run(): .init() must be run first"));
    while (simulate()) iteration++;
    return iteration;
}

bool Controller::simulate() {
    world.fillWithFood();

    if (RENDER_TERMINALVIEW) terminalview.render(world);
    if (RENDER_SDLVIEW) {
        int keysm = sdlview.render(world);
        if (keysm == -1) return false;
    }

    for (auto individual : world.getIndividuals()) {
        auto visibles = world.getObjectsAround(individual->getPosition(), individual->getVision().length);
        auto action = individual->act(visibles);
        std::cout << action.toString() << std::endl;
    }
    if(world.getIndividuals().size() > 0) world.kill(world.getIndividuals().front()->getID());
    return RENDER_SDLVIEW || not world.getIndividuals().empty();
}
