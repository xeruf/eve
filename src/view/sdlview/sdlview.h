#ifndef EVE_SDLVIEW_H
#define EVE_SDLVIEW_H

//#include <SDL2/SDL.h>
//#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdexcept>

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
    [[nodiscard]]Point getRelativePosition(const Point & position, const double worldWidth, const double worldHeight, const int windowHeight, const int windowWidth) const;
    int render(const World & world);
};
#endif //EVE_SDLVIEW_H
