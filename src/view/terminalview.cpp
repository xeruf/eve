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

std::string TerminalView::formatNumberSpacing(int number, int maxLen) {
    std::string formattedString;
    formattedString = std::to_string(number);
    while (formattedString.length() < maxLen) {
        formattedString = std::string(" ").std::string::append(formattedString);
    }
    return formattedString;
};

std::string TerminalView::stringifyEntity(Individual * individual) {
    int id = individual->getID();

    std::string outputString;
    outputString += "ID: " + formatNumberSpacing(id, 3) + " | ";
    outputString += stringifyEntity((Entity *) individual);
    return outputString;
};

std::string TerminalView::stringifyEntity(Entity * entity) {
    int xPos = entity->getPosition().x;
    int yPos = entity->getPosition().y;
    int energy = entity->getEnergy();

    std::string outputString;
    outputString += "X: " + formatNumberSpacing(xPos, 4) + " | ";
    outputString += "Y: " + formatNumberSpacing(yPos, 4) + " | ";
    outputString += "Energy: " + formatNumberSpacing(energy, 3) + "\n";
    return outputString;
};

