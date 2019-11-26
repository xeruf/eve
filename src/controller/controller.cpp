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
                world.rand(ENERGY_d) * INDIVIDUAL_FOOD_FACTOR);
    }

    for (int i = 0; i < AMOUNT_OF_PIERCIES; i++) {
        world.addIndividual<Piercy>(
                world.rand(X_d),
                world.rand(Y_d),
                world.rand(DIRECTION_d),
                world.rand(ENERGY_d) * INDIVIDUAL_FOOD_FACTOR);
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

    if (RENDER_TERMINALVIEW)
        terminalview.render(world);
    if (RENDER_SDLVIEW) {
        int keysm = sdlview.render(world);
        if (keysm == -1) return false;
    }

    std::cout << std::endl << "======== " << iteration << " ========" << std::endl;
    int i = 0;

    for (auto individual : world.getIndividuals()) {
    std::cout << "Ind. " << i++ << ":\t";
        auto action = applyAction(* individual);
        update (* individual, action);
        std::cout << std::endl;
    }

    if(world.getIndividuals().size() > 0) world.kill(world.getIndividuals().front()->getID());
    return RENDER_SDLVIEW || not world.getIndividuals().empty();
}

Action Controller::applyAction (Individual & individual) {
    auto visibles = world.getObjectsInCone(individual.getPosition(), individual.getVision(), Angle(MOUTH_ANGLE));
    Action action = individual.act(visibles);
//    std::cout << action.toString() << ": ";

    switch (action.type) {
        case SLEEP:
            break;
        case MOVE:
            individual.applyForce(Vector(individual.getVision().angle, individual.getEnergy()));
            break;
        case TURN_LEFT:
            individual.turnBy(Angle(- individual.getEnergy() / MAX_FOOD_SIZE / INDIVIDUAL_FOOD_FACTOR * 0.1 * M_PI));
            break;
        case TURN_RIGHT:
            individual.turnBy(Angle(individual.getEnergy() / MAX_FOOD_SIZE / INDIVIDUAL_FOOD_FACTOR * 0.1 * M_PI));
            break;
    }
    return action;
}

void Controller::update (Individual & individual, Action action) {
//    std::cout << individual.applyFriction().length << std::endl;
    individual.applyFriction();

    Point p = individual.getPosition();
    p = individual.updatePosition(std::bind(& World::normalisePosition, & world, std::placeholders::_1));
}
