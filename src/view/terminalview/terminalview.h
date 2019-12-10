
#ifndef EVE_TERMINALVIEW_H
#define EVE_TERMINALVIEW_H

#include "../../model/world/world.h"

namespace TerminalView {
    [[nodiscard]] std::string padIntL(int number, int maxLen);
    void render(const World & world);
    [[nodiscard]] std::string createTable(const World & world);
    [[nodiscard]] std::string stringifyEntity(const Entity * entity);
    [[nodiscard]] std::string stringifyEntity(const Individual * individual);

    template <class T>
    std::string stringifyList(const std::string& header, const std::vector<T *>& list) {
        std::string string =
                "————————————————\n" +
                header + ":\n" +
                "————————————————\n";
        for (auto i : list) {
            string += stringifyEntity(i) + "\n";
        }
        return string;
    }
};

#endif // EVE_TERMINALVIEW_H
