#include "pride.h"

Pride::Pride (Individual const * body) :
        Brain (body),
        prevActions (PRIDE_CHAIN_LENGTH, {{0, body->getEnergy()}, Action (SLEEP)}),
        weights (
                NUMBER_OF_ACTIONS, std::vector <std::vector <std::vector <double>>> (
                        NUMBER_OF_ACTIONS, std::vector <std::vector <double>> (
                                NUMBER_OF_ACTIONS, std::vector <double> (
                                        NUMBER_OF_ACTIONS, 1.0 / NUMBER_OF_ACTIONS
                                )
                        )
                )
        ) {}

Action Pride::think (const std::unique_ptr <std::vector <Object *>> & visibles) {
    update();
    Action new_act = (prevActions [action_idx] = {{visibles->size(), body->getEnergy()}, think()}).second;
    action_idx = ++action_idx % PRIDE_CHAIN_LENGTH;
    return new_act;
}

Action Pride::think() {
    std::vector <double> & tmpWeights = weights
            [prevActions [(action_idx + 0) % PRIDE_CHAIN_LENGTH].second.type]
            [prevActions [(action_idx + 1) % PRIDE_CHAIN_LENGTH].second.type]
            [prevActions [(action_idx + 2) % PRIDE_CHAIN_LENGTH].second.type];

    double random = dice.rand();
    double border = 0;
    for (std::size_t i = 0; i < NUMBER_OF_ACTIONS; i++) {
        if (random < (border += tmpWeights [i])) {
            return Action ((action) (i));
        }
    }
    std::cout << random << " >= " << border << std::endl;
    throw std::logic_error ("Happy rounding errors! (Please ignore this and restart...)");
}

void Pride::update() {
    std::pair <std::pair <int, double>, Action> & lastAction = prevActions [(action_idx + 2) % PRIDE_CHAIN_LENGTH];
    double bonus = body->getEnergy() / lastAction.first.second;
    bonus *=  (1.0 + 0.5 * lastAction.first.first ) / (1.0 + 0.5 * prevActions [(action_idx + 2) % PRIDE_CHAIN_LENGTH].first.first);
    bonus *= PRIDE_FLAT_BONUS;
    if (lastAction.second.type == REPRODUCE) bonus = 1.0 / bonus;
    weights
            [prevActions [(action_idx + 0) % PRIDE_CHAIN_LENGTH].second.type]
            [prevActions [(action_idx + 1) % PRIDE_CHAIN_LENGTH].second.type]
            [prevActions [(action_idx + 2) % PRIDE_CHAIN_LENGTH].second.type]
            [prevActions [(action_idx + 2) % PRIDE_CHAIN_LENGTH].second.type] *= bonus;
    double sum = 0;
    for (std::size_t i = 0; i < NUMBER_OF_ACTIONS; i++) {
        sum += weights
                [prevActions[(action_idx + 0) % PRIDE_CHAIN_LENGTH].second.type]
                [prevActions[(action_idx + 1) % PRIDE_CHAIN_LENGTH].second.type]
                [prevActions[(action_idx + 2) % PRIDE_CHAIN_LENGTH].second.type]
                [i];
    }
    for (std::size_t i = 0; i < NUMBER_OF_ACTIONS; i++) {
        weights
                [prevActions [(action_idx + 0) % PRIDE_CHAIN_LENGTH].second.type]
                [prevActions [(action_idx + 1) % PRIDE_CHAIN_LENGTH].second.type]
                [prevActions [(action_idx + 2) % PRIDE_CHAIN_LENGTH].second.type]
                [i] += 0.2 * sum;
    }
    for (std::size_t i = 0; i < NUMBER_OF_ACTIONS; i++) {
        weights
                [prevActions [(action_idx + 0) % PRIDE_CHAIN_LENGTH].second.type]
                [prevActions [(action_idx + 1) % PRIDE_CHAIN_LENGTH].second.type]
                [prevActions [(action_idx + 2) % PRIDE_CHAIN_LENGTH].second.type]
                [i] /= sum * 2;
    }
}
