#ifndef EVE_SDLVIEW_H
#define EVE_SDLVIEW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "../../config.h"
#include "../../model/world/world.h"

class SDLView {
private:
    void setupsdl(const World & world);
    void draw(const World & world);
    void stop();
    SDL_Window * window{};
    SDL_Renderer * renderer{};
    SDL_DisplayMode DM;
public:
    [[nodiscard]]Point getRelativePosition(const Point & position, double worldWidth, double worldHeight, double windowWidth, double windowHeight) const;
    int render(const World & world);
};
#endif //EVE_SDLVIEW_H
