#include "sdlview.h"
#include <stdexcept>

void SDLView::setupsdl(const World & world) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::string error_msg = "SDL_Init Error: ";
        std::string SDL_Error = SDL_GetError();
        error_msg += SDL_Error;
        throw std::runtime_error(error_msg);
    }
    float dimensions = world.WIDTH / world.HEIGHT;
    SDL_GetCurrentDisplayMode(0, &DM);
    window = SDL_CreateWindow("Eve", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DM.h * dimensions, DM.h, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        SDL_Quit();
        std::string error_msg = "SDL_Init Error: ";
        std::string SDL_Error = SDL_GetError();
        error_msg += SDL_Error;
        throw std::runtime_error(error_msg);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_Quit();
        std::string error_msg = "SDL_Init Error: ";
        std::string SDL_Error = SDL_GetError();
        error_msg += SDL_Error;
        throw std::runtime_error(error_msg);
    }
}

Point SDLView::getRelativePosition(const Point & position, const double worldWidth, const double worldHeight) const {
    double x = position.x * (DM.w / worldWidth);
    double y = position.y * (DM.h / worldHeight);
    Point relativePosition = {x, y};
    return relativePosition;
}

void SDLView::draw(const World &world) {
   SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, 0xFF);
   SDL_RenderClear(renderer);

   for (auto individual : world.getIndividuals()) {
       Point relativePosition = getRelativePosition(individual->getPosition(), world.WIDTH, world.HEIGHT);
       filledCircleColor(renderer, relativePosition.x, relativePosition.y, individual->getRadius() * SCALE_FACTOR, 0xFF00FFFF);

       Point relativeVision = getRelativePosition(individual->getPosition() + individual->getVision(), world.WIDTH, world.HEIGHT);
       thickLineColor(renderer, relativePosition.x, relativePosition.y, relativeVision.x, relativeVision.y, 3, 0xFF000000);
   }

   for (auto food : world.getFood()) {
       Point relativePosition = getRelativePosition(food->getPosition(), world.WIDTH, world.HEIGHT);
       aacircleColor(renderer, relativePosition.x, relativePosition.y, food->getRadius() * SCALE_FACTOR, 0xFF0000FF);
   }

   SDL_RenderPresent(renderer);
   SDL_Delay(RENDER_DELAY);
}

void SDLView::stop() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
};

int SDLView::render(const World &world) {
    if (!renderer) setupsdl(world);
    SDL_Event event;

    if (SDL_PollEvent(& event)) {
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



