#include "controller.h"

Controller::Controller(double WIDTH, double HEIGHT, double ENERGY) :
    world(World(WIDTH, HEIGHT, ENERGY)) {
}

void Controller::init() {

    {
        int i, j = 0;
        try {
            for (i = 0; i < AMOUNT_OF_FREDS; i++) {
                world.addIndividual<Fred>(
                        world.rand(X_d),
                        world.rand(Y_d),
                        world.rand(DIRECTION_d),
                        world.rand(ENERGY_d) * INDIVIDUAL_FOOD_FACTOR);
            }

            for (j = 0; j < AMOUNT_OF_PIERCIES; j++) {
                world.addIndividual<Piercy>(
                        world.rand(X_d),
                        world.rand(Y_d),
                        world.rand(DIRECTION_d),
                        world.rand(ENERGY_d) * INDIVIDUAL_FOOD_FACTOR);
            }
        } catch (std::overflow_error & e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "Initialised with " << i << " Freds and " << j << " Piercies" << std::endl;
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

    std::cout << std::endl << "======== " << iteration << " ========" << std::endl;
    int i = 0;

    for (auto individual : world.getIndividuals()) {
    std::cout << "Ind. " << i++ << ":\t";
        auto action = applyAction(* individual);
        update (* individual, action);
    }

    return not world.getIndividuals().empty();
}

action Controller::applyAction (Individual & individual) {
    auto visibles = world.getObjectsInCone(individual.getPosition(), individual.getVision(), Angle(MOUTH_ANGLE));
    action action = individual.act(visibles).type;
    switch (action) {
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

void Controller::update (Individual & individual, action action) {
//    std::cout << individual.applyFriction().length << std::endl;
    individual.applyFriction();
    individual.updatePosition(std::bind(& World::normalisePosition, & world, std::placeholders::_1));
    updateEnergy (individual, action);
    eatNearbyFood (individual);
}

void Controller::updateEnergy (Individual & individual, action action) {
    double multiplier;
    switch (action) {
        case SLEEP:
            multiplier = SLEEP_FACTOR;
            break;
        case MOVE:
            multiplier = MOVE_FACTOR;
            break;
        case TURN_RIGHT:
        case TURN_LEFT:
            multiplier = TURN_FACTOR;
            break;
    }
    if (individual.updateEnergy (multiplier) < SURVIVAL_THRESHOLD) {
        world.kill (individual.getID());
    }
}

void Controller::eatNearbyFood (Individual & individual) {
    std::vector<Food> Foods = * world.getFoodsAround(
            individual.getPosition(),
            individual.getRadius() + sqrt(MAX_FOOD_SIZE) / M_PI);

    for (auto & food : Foods) {
        world.remove (& food);
    }
}