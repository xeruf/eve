#ifndef EVE_SDLVIEW_H
#define EVE_SDLVIEW_H

#include <stdexcept>
#include <thread>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "../../config.h"
#include "../../model/world/world.h"
#include "../view.h"

class SDLView : public View {
private:
    void draw(const World & world);
    SDL_Window * window{};
    SDL_Renderer * renderer{};
    SDL_DisplayMode DM;
public:
    void init(const World & world) override;
    void stop() override;
    int render(const World & world);
    [[nodiscard]]Point getRelativePosition(const Point & position, double worldWidth, double worldHeight, double windowWidth, double windowHeight) const;
};
#endif //EVE_SDLVIEW_H
