#include "terminalview.h"
#include <iostream>

void TerminalView::render(World & world) {
    std::string outputString;

    outputString += "—————————————————————————————————————————\n"
                    "Food:\n"
                    "—————————————————————————————————————————\n";

    std::vector<Food> food = world.getFood();

    for (int i = 0; i < food.size(); ++i) {
        outputString += stringifyFood(food[i]);
    }

    outputString += "—————————————————————————————————————————\n"
                    "Entities:\n"
                    "—————————————————————————————————————————\n";

    std::vector<Individual> individuals = world.getIndividuals();
    for (int i = 0; i < individuals.size(); ++i) {
        outputString += stringifyEntity(individuals[i]);
    }

    std::cout << outputString << std::endl;
}

std::string TerminalView::formatNumberSpacing(int number, int maxLen) {
    std::string formattedString;
    formattedString = std::to_string(number);
    while (formattedString.length() < maxLen) {
        formattedString = std::string(" ").std::string::append(formattedString);
    }
    return formattedString;
};

std::string TerminalView::stringifyFood(Food & food) {
    int xPos = food.getPosition().x;
    int yPos = food.getPosition().y;
    int energy = food.getEnergy();

    std::string formattedXPos = formatNumberSpacing(xPos, 4);
    std::string formattedYPos = formatNumberSpacing(yPos, 4);
    std::string formattedEnergy = formatNumberSpacing(energy, 3);

    std::string outputString;
    outputString += "X: " + formattedXPos + " | ";
    outputString += "Y: " + formattedYPos + " | ";
    outputString += "Energy: " + formattedEnergy + "\n";
    return outputString;
};

std::string TerminalView::stringifyEntity(Entity & entity) {

};
