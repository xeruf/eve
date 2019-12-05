#include "sdlview.h"

struct bla {
    SDLView * view;
    World world;
};

void SDLView::init(const World &world) {
    std::cout << "Starting SDL initialization\n";
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::string error_msg = "SDL_Init Error: ";
        std::string SDL_Error = SDL_GetError();
        error_msg += SDL_Error;
        throw std::runtime_error(error_msg);
    }
    float aspectRatio = world.WIDTH / world.HEIGHT;
    SDL_GetCurrentDisplayMode(0, &DM);
    window = SDL_CreateWindow("Eve", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DM.h * aspectRatio, DM.h,
                              SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        SDL_Quit();
        std::string error_msg = "SDL_Init Error: ";
        std::string SDL_Error = SDL_GetError();
        error_msg += SDL_Error;
        throw std::runtime_error(error_msg);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_Quit();
        std::string error_msg = "SDL_Init Error: ";
        std::string SDL_Error = SDL_GetError();
        error_msg += SDL_Error;
        throw std::runtime_error(error_msg);
    }

    SDL_Thread *threadID = SDL_CreateThread(
            [](void *data) {
                bla * dat = (bla*) data;
                while (dat->view->render(dat->world)) {
                    SDL_Delay(RENDER_DELAY);
                }
                return 0;
            }, "SDLRenderThread", new bla{.view = this, .world = world});
    std::cout << "Started the render thread\n";
}

int SDLView::render(const World &world) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            stop();
            return -1;
        } else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == 113) {
                stop();
                return -1;
            }
            return event.key.keysym.sym;
        }
    }
    draw(world);
    return 0;
}

void SDLView::draw(const World &world) {
    SDL_SetRenderDrawColor(renderer, (Uint8) BACKGROUND_COLOR, (Uint8) (BACKGROUND_COLOR >> 8u),
                           (Uint8) (BACKGROUND_COLOR >> 16u), (Uint8) (BACKGROUND_COLOR >> 24u));
    SDL_RenderClear(renderer);

    for (auto food : world.getFood()) {
        Point relativePosition = getRelativePosition(food->getPosition(), world.WIDTH, world.HEIGHT, DM.w, DM.h);
        filledCircleColor(renderer, relativePosition.x, relativePosition.y, food->getRadius() * SCALE_FACTOR,
                          FOOD_COLOR);
    }

    for (auto individual : world.getIndividuals()) {
        Point relativePosition = getRelativePosition(individual->getPosition(), world.WIDTH, world.HEIGHT, DM.w, DM.h);
        filledCircleColor(renderer, relativePosition.x, relativePosition.y, individual->getRadius() * SCALE_FACTOR,
                          INDIVIDUAL_COLOR);

        Point relativeVision = getRelativePosition(individual->getPosition() + individual->getVision(), world.WIDTH,
                                                   world.HEIGHT, DM.w, DM.h);
        thickLineColor(renderer, relativePosition.x, relativePosition.y, relativeVision.x, relativeVision.y, 3,
                       POINTER_COLOR);
    }

    SDL_RenderPresent(renderer);
}

Point SDLView::getRelativePosition(const Point &position, double worldWidth, double worldHeight, double windowWidth,
                                   double windowHeight) const {
    double x = position.x * (windowWidth / worldWidth);
    double y = position.y * (windowHeight / worldHeight);
    Point relativePosition = {x, y};
    return relativePosition;
}

void SDLView::stop() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
};
