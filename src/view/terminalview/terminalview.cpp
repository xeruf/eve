#include "terminalview.h"
#include <iostream>

void TerminalView::render(const World & world) const {
    std::string table = createTable(world);
    std::cout << table << std::endl;
}

std::string TerminalView::createTable(const World & world) const {
    std::string outputString;

    outputString += "—————————————————————————————————————————\n"
                    "Food:\n"
                    "—————————————————————————————————————————\n";

    std::vector<Food *> food = world.getFood();

    for (auto f : food) {
        outputString += stringifyEntity(f);
    }

    outputString += "—————————————————————————————————————————\n"
                    "Individuals:\n"
                    "—————————————————————————————————————————\n";

    std::vector<Individual *> individuals = world.getIndividuals();
    for (auto i : individuals) {
        outputString += stringifyEntity(i);
    }

    return outputString;
};

std::string TerminalView::padIntL(int number, int maxLen) const {
    std::string numberString = std::to_string(number);
    std::string paddedString(maxLen - numberString.length(), ' ');
    paddedString += numberString;
    return paddedString;
};

std::string TerminalView::stringifyEntity(const Individual * individual) const {
    int id = individual->getID();

    std::string outputString;
    outputString += "ID: " + padIntL(id, 3) + " | ";
    outputString += stringifyEntity((Entity *) individual);
    return outputString;
};

std::string TerminalView::stringifyEntity(const Entity * entity) const {
    int xPos = entity->getPosition().x;
    int yPos = entity->getPosition().y;
    int energy = entity->getEnergy();

    std::string outputString;
    outputString += "X: " + padIntL(xPos, 4) + " | ";
    outputString += "Y: " + padIntL(yPos, 4) + " | ";
    outputString += "Energy: " + padIntL(energy, 3) + "\n";
    return outputString;
};

