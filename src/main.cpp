#include "main.h"

int main() {
    Controller controller = Controller(WIDTH, HEIGHT, ENERGY);
    controller.init();
    controller.run();
}