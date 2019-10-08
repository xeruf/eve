
#ifndef EVE_TERMINALVIEW_H
#define EVE_TERMINALVIEW_H

#include "../model/world/world.h"

class TerminalView {
private:
    std::string formatNumberSpacing(int number, int maxLen);
public:
    void render(World world);
    std::string createTable(World world);
    std::string stringifyFood(Food food);
    std::string stringifyEntity(Entity & entity);
};

#endif // EVE_TERMINALVIEW_H
