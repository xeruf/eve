#include "main.h"

int main(int argc, char * argv[]) {
    Controller controller = Controller(WIDTH, HEIGHT, ENERGY);
    controller.init();
    controller.run();
    return 0;
}