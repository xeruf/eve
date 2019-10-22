#include "main.h"

int main(int argc, char * argv[]) {
    Controller controller = Controller(WIDTH, HEIGHT, ENERGY);
    controller.init();
    controller.run();

    // debug terminalview render function
    TerminalView terminalView = TerminalView();
    World world = World(1000, 1000, 1000);

    Fred * fred1 = new Fred(123, 321, 100);
    Fred * fred2 = new Fred(138, 153, 70);
    Fred * fred3 = new Fred(420, 420, 5);

    Food * food1 = new Food(500, 689, 10);
    Food * food2 = new Food(1000, 1000, 100);
    Food * food3 = new Food(0, 0, 1);

    world.addIndividual(fred1);
    world.addIndividual(fred2);
    world.addIndividual(fred3);

    world.addFood(food1);
    world.addFood(food2);
    world.addFood(food3);

    terminalView.render(world);
    return 0;
}
