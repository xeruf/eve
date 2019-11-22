#include "sdlview.h"
#include <stdexcept>

void SDLView::setupsdl(const World & world) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::string error_msg = "SDL_Init Error: ";
        std::string SDL_Error = SDL_GetError();
        error_msg += SDL_Error;
        throw std::runtime_error(error_msg);
    }

    window = SDL_CreateWindow("Eve", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, world.WIDTH, world.HEIGHT, SDL_WINDOW_OPENGL);
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

void SDLView::draw(const World &world) {
   SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, 0xFF);
   SDL_RenderClear(renderer);

   for (auto individual : world.getIndividuals()) {
       circleColor(renderer, individual->getPosition().x, individual->getPosition().y, individual->getRadius(), 0xFF00FFFF);
   }

   SDL_RenderPresent(renderer);
   SDL_Delay(100);
}

void SDLView::stop() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
};

int SDLView::render(const World &world) {
    if (!renderer) setupsdl(world);

    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            stop();
            return 1;
        }
    }
    draw(world);
    return 0;
}


