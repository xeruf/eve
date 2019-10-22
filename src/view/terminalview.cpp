#include "terminalview.h"

std::string TerminalView::formatNumberSpacing(int number, int maxLen) {
    std::string formattedString;
    formattedString = std::to_string(number);
    while (formattedString.length() < maxLen) {
        formattedString = std::string(" ").std::string::append(formattedString);
    }
    return formattedString;
};

std::string TerminalView::stringifyFood(Food food) {
    int xPos = food.getPosition().x;
    int yPos = food.getPosition().y;
    int energy = food.getEnergy();

    std::string formattedXPos;
    std::string formattedYPos;
    std::string formattedEnergy;

    formattedXPos = formatNumberSpacing(xPos, 4);
    formattedYPos = formatNumberSpacing(yPos, 4);
    formattedEnergy = formatNumberSpacing(energy, 3);

    std::string outputString;
    outputString += "X: " + formattedXPos + " | ";
    outputString += "Y: " + formattedYPos + " | ";
    outputString += "Energy: " + formattedEnergy + "\n";
    return outputString;
};
