#include "controller.h"

Controller::Controller(double WIDTH, double HEIGHT, double ENERGY) :
    world(World(WIDTH, HEIGHT, ENERGY)) {
}

void Controller::init() {
    {
        int amounts[] = {AMOUNT_OF_FREDS, AMOUNT_OF_BRANDIES, AMOUNT_OF_PIERCIES};
        for (int i = 0; i < 3; i++) {
            std::cout << "Amount of ";
            int counter;
            try {
                switch (i) {
                    case 0: std::cout << "Freds:    "; break;
                    case 1: std::cout << "Brandies: "; break;
                    case 2: std::cout << "Piercies: "; break;
                }
                for (counter = 0; counter < amounts[i]; counter++) {
                    switch (i) {
                        case 0:
                            world.addIndividual<Fred>(
                                    world.rand(X_d),
                                    world.rand(Y_d),
                                    world.rand(DIRECTION_d),
                                    world.rand(ENERGY_d) * INDIVIDUAL_FOOD_FACTOR);
                            break;
                        case 1:
                            world.addIndividual<Brandy>(
                                    world.rand(X_d),
                                    world.rand(Y_d),
                                    world.rand(DIRECTION_d),
                                    world.rand(ENERGY_d) * INDIVIDUAL_FOOD_FACTOR);
                            break;
                        case 2:
                            world.addIndividual<Piercy>(
                                    world.rand(X_d),
                                    world.rand(Y_d),
                                    world.rand(DIRECTION_d),
                                    world.rand(ENERGY_d) * INDIVIDUAL_FOOD_FACTOR);
                            break;
                    }
                }
            }
            catch (std::overflow_error & e) {
                    std::cerr << e.what() << std::endl;
            }
            std::cout << counter << std::endl;
        }
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
            individual.applyForce(Vector(individual.getVision().angle, MOVE_RATE + ACTION_FACTOR_MOVE * individual.getEnergy()));
            break;
        case TURN_LEFT:
            individual.turnBy(Angle(- (int) (TURN_RATE + ACTION_FACTOR_TURN * individual.getEnergy())));
            break;
        case TURN_RIGHT:
            individual.turnBy(Angle((int) (TURN_RATE + ACTION_FACTOR_TURN * individual.getEnergy())));
            break;
    }
    return action;
}

void Controller::update (Individual & individual, action action) {
    individual.applyFriction();
    individual.updatePosition(std::bind(& World::normalisePosition, & world, std::placeholders::_1));
    updateEnergy (individual, action);
    eatNearbyFood (individual);
}

void Controller::updateEnergy (Individual & individual, action action) {
    double multiplier;
    switch (action) {
        case SLEEP:
            multiplier = ENERGY_FACTOR_SLEEP;
            break;
        case MOVE:
            multiplier = ENERGY_FACTOR_MOVE;
            break;
        case TURN_RIGHT:
        case TURN_LEFT:
            multiplier = ENERGY_FACTOR_TURN;
            break;
    }
    double energyLevel = individual.updateEnergy (multiplier);

    if (energyLevel < SURVIVAL_THRESHOLD) {
        world.kill (individual.getID());
    }
    if (energyLevel > REPRODUCTION_THRESHOLD) {
        world.addChild (individual.reproduce(world.getIndividuals().size()));
    }
}

void Controller::eatNearbyFood (Individual & individual) {
    std::vector<Food *> Foods = * world.getFoodsAround(
            individual.getPosition(),
            individual.getRadius() + sqrt(MAX_FOOD_SIZE) / M_PI);

    for (auto food : Foods) {
        individual.eat(* food);
        world.remove (food);
    }
}