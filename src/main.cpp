#include "main.h"

int main(int argc, char * argv[]) {
    if (argc > 1) {
        Deisy::nature = std::stoi (argv[1]);
    }

    Controller controller = Controller(WIDTH, HEIGHT, ENERGY);
    controller.init();
    controller.run();
}
