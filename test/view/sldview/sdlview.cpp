#include "../../../src/view/sdlview/sdlview.h"
#include <catch2/catch.hpp>
#include <exception>

TEST_CASE("SDLView.getRelativePosition can calculate the correct position on the screen") {
    SDLView sdlview = SDLView();

    const int windowWidth = 1080;
    const int windowHeight = 1080;
    const double worldWidth = 1000;
    const double worldHeight = 1000;

    SECTION("The conversion works successfully at minimum position") {
        Point position = {0,0};
        Point expectedPosition = {0,0};
        REQUIRE(
                sdlview.getRelativePosition(position, worldWidth, worldHeight, windowWidth, windowHeight) == expectedPosition
                );
    }

    SECTION("The conversion works successfully at maximum position") {
        Point position = {1000,1000};
        Point expectedPosition = {1080,1080};
        REQUIRE(
                sdlview.getRelativePosition(position, worldWidth, worldHeight, windowWidth, windowHeight) == expectedPosition
        );
    }

    SECTION("The conversion works successfully at arbitrary position of 756, 123") {
        Point position = {756,123};
        Point expectedPosition = {816.48, 132.84};
        REQUIRE(
                sdlview.getRelativePosition(position, worldWidth, worldHeight, windowWidth, windowHeight) == expectedPosition
        );
    }
}