#include "main.h"

#define WIDTH 1000
#define HEIGHT 1000
#define ENERGY 1000

int main(int argc, char * argv[]) {
    Controller controller = Controller(WIDTH, HEIGHT, ENERGY);
    controller.init();
    controller.run();
    return 0;
}