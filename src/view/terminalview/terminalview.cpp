#include "terminalview.h"
#include <iostream>

std::string TerminalView::padIntL(int number, int maxLen) {
    std::string numberString = std::to_string(number);
    if(numberString.length() >= maxLen)
        return numberString;
    std::string paddedString(maxLen - numberString.length(), ' ');
    paddedString += numberString;
    return paddedString;
};

void TerminalView::render(const World & world) {
    std::string table = createTable(world);
    std::cout << table << std::endl;
}

std::string TerminalView::createTable(const World & world) {
    return stringifyList("Food", world.getFood()) +
    stringifyList("Individuals", world.getIndividuals());
};

std::string TerminalView::stringifyEntity(const Individual * individual) {
    std::string outputString;
    outputString += "ID: " + padIntL(individual->getID(), 3) + " | ";
    outputString += stringifyEntity((Entity *) individual);
    return outputString;
};

std::string TerminalView::stringifyEntity(const Entity * entity) {
    auto xPos = entity->getPosition().x;
    auto yPos = entity->getPosition().y;
    auto energy = entity->getEnergy();

    std::string outputString;
    outputString += "X: " + padIntL(xPos, 4) + " | ";
    outputString += "Y: " + padIntL(yPos, 4) + " | ";
    outputString += "Energy: " + padIntL(energy, 3);
    return outputString;
};

