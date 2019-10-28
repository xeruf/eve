#include "terminalview.h"
#include <iostream>

void TerminalView::render(World & world) {
    std::string table = createTable(world);
    std::cout << table << std::endl;
}

std::string TerminalView::createTable(World & world) {
    std::string outputString;

    outputString += "—————————————————————————————————————————\n"
                    "Food:\n"
                    "—————————————————————————————————————————\n";

    std::vector<Food *> food = world.getFood();

    for (int i = 0; i < food.size(); ++i) {
        outputString += stringifyEntity(food[i]);
    }

    outputString += "—————————————————————————————————————————\n"
                    "Individuals:\n"
                    "—————————————————————————————————————————\n";

    std::vector<Individual *> individuals = world.getIndividuals();
    for (int i = 0; i < individuals.size(); ++i) {
        outputString += stringifyEntity(individuals[i]);
    }

    return outputString;
};

std::string TerminalView::padIntL(int number, int maxLen) {
    std::string numberString = std::to_string(number);
    std::string paddedString(maxLen - numberString.length(), ' ');
    paddedString += numberString;
    return paddedString;
};

std::string TerminalView::stringifyEntity(Individual * individual) {
    int id = individual->getID();

    std::string outputString;
    outputString += "ID: " + padIntL(id, 3) + " | ";
    outputString += stringifyEntity((Entity *) individual);
    return outputString;
};

std::string TerminalView::stringifyEntity(Entity * entity) {
    int xPos = entity->getPosition().x;
    int yPos = entity->getPosition().y;
    int energy = entity->getEnergy();

    std::string outputString;
    outputString += "X: " + padIntL(xPos, 4) + " | ";
    outputString += "Y: " + padIntL(yPos, 4) + " | ";
    outputString += "Energy: " + padIntL(energy, 3) + "\n";
    return outputString;
};

