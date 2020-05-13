#include "controller.h"

Controller::Controller(double WIDTH, double HEIGHT, double ENERGY) :
    world(World(WIDTH, HEIGHT, ENERGY)) {
}

void Controller::init() {
    {
        std::vector <int> amounts {AMOUNT_OF_FREDS, AMOUNT_OF_BRANDIES, AMOUNT_OF_PIERCIES, AMOUNT_OF_DEISIES};
        for (int i = 0; i < amounts.size(); i++) {
            std::cout << "Amount of ";
            int counter;
            try {
                switch (i) {
                    case 0: std::cout << "Freds:    "; break;
                    case 1: std::cout << "Brandies: "; break;
                    case 2: std::cout << "Piercies: "; break;
                    case 3: std::cout << "Deisies:  "; break;
                }
                for (counter = 0; counter < amounts[i]; counter++) {
                    switch (i) {
                        case 0:
                            world.addIndividual<Fred>(
                                    world.rand(X_d),
                                    world.rand(Y_d),
                                    world.rand(DIRECTION_d),
                                    INDIVIDUAL_START_SIZE);
                            break;
                        case 1:
                            world.addIndividual<Brandy>(
                                    world.rand(X_d),
                                    world.rand(Y_d),
                                    world.rand(DIRECTION_d),
                                    INDIVIDUAL_START_SIZE);
                            break;
                        case 2:
                            world.addIndividual<Piercy>(
                                    world.rand(X_d),
                                    world.rand(Y_d),
                                    world.rand(DIRECTION_d),
                                    INDIVIDUAL_START_SIZE);
                            break;
                        case 3:
                            world.addIndividual<Deisy>(
                                    world.rand(X_d),
                                    world.rand(Y_d),
                                    world.rand(DIRECTION_d),
                                    INDIVIDUAL_START_SIZE);
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
        double energyDiff = abs(w->ENERGY - w->getEnergy());
        return new Food(
                w->rand(X_d),
                w->rand(Y_d),
                energyDiff < MAX_FOOD_SIZE ?
                energyDiff :
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
        std::cout << TerminalView::stringifyList("Individuals", world.getIndividuals());
    if (RENDER_SDLVIEW) {
        int keysm = sdlview.render(world);
        if (keysm == -1) return false;
    }

    for (auto * individual : world.getIndividuals()) {
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
        case REPRODUCE:
            if (individual.getEnergy() > REPRODUCTION_THRESHOLD) {
                world.addChild (individual.reproduce(world.nextId()));
            } else action = SLEEP;
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
    double energy = individual.getEnergy();
    double usage = energy * IDLE_ENERGY_USE;
    switch (action) {
        case MOVE:
            usage += MOVE_COST;
            break;
        case TURN_LEFT:
        case TURN_RIGHT:
            usage += TURN_COST;
            break;
        case SLEEP:
            break;
    }
    individual.updateEnergy(energy - usage);
    world.usedEnergy(usage);

    energy = individual.getEnergy();
    if (energy < SURVIVAL_THRESHOLD) {
        world.kill (individual.getID());
    }
}

void Controller::eatNearbyFood (Individual & individual) {
    double energy = world.removeFoodsAround(
            individual.getPosition(),
            individual.getRadius() + sqrt(MAX_FOOD_SIZE) / M_PI);
    individual.addEnergy(energy);
}