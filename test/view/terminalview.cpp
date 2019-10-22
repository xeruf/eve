#include "../../src/view/terminalview.h"
#include <catch2/catch.hpp>
#include <exception>

TEST_CASE("A string table can be created"){
    TerminalView terminalView = TerminalView();

    std::string table =
        "—————————————————————————————————————————\n"
        "Food:\n"
        "—————————————————————————————————————————\n"
        "X:  500 | Y:  689 | Energy:  10\n"
        "X: 1000 | Y: 1000 | Energy:  10\n"
        "X:   43 | Y:  978 | Energy:  20\n"
        "—————————————————————————————————————————\n"
        "Entities:\n"
        "—————————————————————————————————————————\n"
        "ID:  23 | X:  123 | Y:  321 | Energy: 100\n"
        "ID:  24 | X:  138 | Y:  153 | Energy:  70\n"
        "ID:  69 | X:  420 | Y:  420 | Energy:   5\n";

    World world = World(1000, 1000, 40);
    SECTION(""){}

    // Food tests
    Food food1 = Food(500, 689, 10);
    SECTION("stringifyFood can convert a Food object into a string") {
        REQUIRE(
            terminalView.stringifyFood(food1) == "X:  500 | Y:  689 | Energy:  10\n"
        );
    }

    Food food2 = Food(1000, 1000, 100);
    SECTION("stringifyFood correctly formats food at max values") {
        REQUIRE(
            terminalView.stringifyFood(food2) == "X: 1000 | Y: 1000 | Energy: 100\n"
        );
    }

    Food food3 = Food(0, 0, 1);
    SECTION("stringifyFood correctly formats food at minimum values"){
        REQUIRE(
            terminalView.stringifyFood(food3) == "X:    0 | Y:    0 | Energy:   1\n"
        );
    }
}
