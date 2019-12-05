
#ifndef EVE_TERMINALVIEW_H
#define EVE_TERMINALVIEW_H

#include "../../model/world/world.h"

class TerminalView {
private:
    [[nodiscard]] static std::string padIntL(int number, int maxLen);
public:
    void render(const World & world) const;
    [[nodiscard]] std::string createTable(const World & world) const;
    [[nodiscard]] static std::string stringifyEntity(const Entity * entity);
    [[nodiscard]] static std::string stringifyEntity(const Individual * individual);
};

#endif // EVE_TERMINALVIEW_H
