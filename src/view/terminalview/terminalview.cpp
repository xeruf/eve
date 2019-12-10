#include "terminalview.h"
#include <iostream>

void TerminalView::render(const World & world) {
    std::string table = createTable(world);
    std::cout << table << std::endl;
}

std::string TerminalView::createTable(const World & world) {
    std::string foodString =
            "—————————————————————————————————————————\n"
            "Food:\n"
            "—————————————————————————————————————————\n";

    std::vector<Food *> food = world.getFood();
    for (auto f : food) {
        foodString += stringifyEntity(f);
    }

    std::string individualString =
            "—————————————————————————————————————————\n"
            "Individuals:\n"
            "—————————————————————————————————————————\n";
    std::vector<Individual *> individuals = world.getIndividuals();
    for (auto i : individuals) {
        individualString += stringifyEntity(i);
    }

    return foodString + individualString;
};

std::string TerminalView::padIntL(int number, int maxLen) {
    std::string numberString = std::to_string(number);
    if(numberString.length() >= maxLen)
        return numberString;
    std::string paddedString(maxLen - numberString.length(), ' ');
    paddedString += numberString;
    return paddedString;
};

std::string TerminalView::stringifyEntity(const Individual * individual) {
    int id = individual->getID();

    std::string outputString;
    outputString += "ID: " + padIntL(id, 3) + " | ";
    outputString += stringifyEntity((Entity *) individual);
    return outputString;
};

std::string TerminalView::stringifyEntity(const Entity * entity) {
    int xPos = entity->getPosition().x;
    int yPos = entity->getPosition().y;
    int energy = entity->getEnergy();

    std::string outputString;
    outputString += "X: " + padIntL(xPos, 4) + " | ";
    outputString += "Y: " + padIntL(yPos, 4) + " | ";
    outputString += "Energy: " + padIntL(energy, 3) + "\n";
    return outputString;
};

