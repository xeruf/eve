#include "terminalview.h"

std::string TerminalView::stringifyFood(Food food){
    std::string outputString;
    outputString += "X:  " + std::to_string(food.getPosition().x) + " | ";
    outputString += "Y:  " + std::to_string(food.getPosition().y) + " | ";
    outputString += "Value: " + std::to_string(food.getValue()) + "\n";
    return outputString;
};
