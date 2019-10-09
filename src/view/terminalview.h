
#ifndef EVE_TERMINALVIEW_H
#define EVE_TERMINALVIEW_H

#include "../model/world/world.h"

class TerminalView {
private:
    std::string formatNumberSpacing(int number, int maxLen);
public:
    void render(const World world);
    std::string createTable(const World world);
    std::string stringifyFood(const Food food);
    std::string stringifyEntity(const Entity & entity);
};

#endif // EVE_TERMINALVIEW_H
