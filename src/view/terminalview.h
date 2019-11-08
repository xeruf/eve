
#ifndef EVE_TERMINALVIEW_H
#define EVE_TERMINALVIEW_H

#include "../model/world/world.h"

class TerminalView {
private:
    [[nodiscard]] std::string padIntL(int number, int maxLen) const;
public:
    void render(const World & world) const;
    [[nodiscard]] std::string createTable(const World & world) const;
    [[nodiscard]] std::string stringifyEntity(const Entity * entity) const;
    [[nodiscard]] std::string stringifyEntity(const Individual * individual) const;
};

#endif // EVE_TERMINALVIEW_H
