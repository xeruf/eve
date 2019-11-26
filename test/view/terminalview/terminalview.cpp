/*
#include "../../../src/view/terminalview/terminalview.h"
#include "../../../src/model/object/entity/individual/fred/fred.h"
#include <catch2/catch.hpp>
#include <exception>

TEST_CASE("A string table can be created"){
    TerminalView terminalView = TerminalView();

    std::string table =
        "—————————————————————————————————————————\n"
        "Food:\n"
        "—————————————————————————————————————————\n"
        "X:  500 | Y:  689 | Energy:  10\n"
        "X: 1000 | Y: 1000 | Energy: 100\n"
        "X:    0 | Y:    0 | Energy:   1\n"
        "—————————————————————————————————————————\n"
        "Individuals:\n"
        "—————————————————————————————————————————\n"
        "ID:   0 | X:  123 | Y:  321 | Energy: 100\n"
        "ID:   1 | X:  138 | Y:  153 | Energy:  70\n"
        "ID:   2 | X:  420 | Y:  420 | Energy:   5\n";

    World world = World(1000, 1000, 1000);
    Fred * fred1 = new Fred(123, 321, 0,  100);
    Fred * fred2 = new Fred(138, 153, 0, 70);
    Fred * fred3 = new Fred(420, 420, 0, 5);

    Food * food1 = new Food(500, 689, 10);
    Food * food2 = new Food(1000, 1000, 100);
    Food * food3 = new Food(0, 0, 1);

    world.addIndividual(fred1);
    world.addIndividual(fred2);
    world.addIndividual(fred3);

    world.addFood(food1);
    world.addFood(food2);
    world.addFood(food3);


    // Food tests
    SECTION("stringifyFood can convert a Food object into a string") {
        REQUIRE(
            terminalView.stringifyEntity(food1) == "X:  500 | Y:  689 | Energy:  10\n"
        );
    }

    SECTION("stringifyFood correctly formats food at max values") {
        REQUIRE(
            terminalView.stringifyEntity(food2) == "X: 1000 | Y: 1000 | Energy: 100\n"
        );
    }

    SECTION("stringifyFood correctly formats food at minimum values"){
        REQUIRE(
            terminalView.stringifyEntity(food3) == "X:    0 | Y:    0 | Energy:   1\n"
        );
    }

    // Individual tests
    SECTION("stringifyIndividual can convert an individual object into a string") {
        REQUIRE(
            terminalView.stringifyEntity(fred1) == "ID:  55 | X:  123 | Y:  321 | Energy: 100\n"
        );
    }

    // createTable tests
    SECTION("createTable correctly formats the whole table"){
        REQUIRE(
            terminalView.createTable(world) == table
        );
    }
}
*/
