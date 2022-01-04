#ifndef EVE_CONTROLLER_H
#define EVE_CONTROLLER_H

#include "../config.h"
#include "../model/object/entity/food/food.h"
#include "../model/object/entity/individual/fred/fred.h"
#include "../model/object/entity/individual/brandy/brandy.h"
#include "../model/object/entity/individual/piercy/piercy.h"
#include "../model/object/entity/individual/deisy/deisy.h"
#include "../model/random/random.h"
#include "../view/terminalview/terminalview.h"
#include "../view/sdlview/sdlview.h"
#include "../model/world/world.h"

#include <cmath>
#include <stdexcept>
#include <vector>
#include <map>
#include <functional>

/** Main class for the EVE project - initialise then run to start the simulation */
class Controller {
private:
    long iteration = 0;
    bool initialised = false;

    /** Calculates a new tick of the world.
     * @return Whether to continue running */
    bool simulate();

    /** Requests an action of Individual and reacts to that. */
    action applyAction (Individual & individual);

    /** Updates the physical properties of individuals. */
    void update (Individual & individual, action action);

    /** Update the energy level of the individuals */
    void updateEnergy (Individual & individual, action action);

    /** Have the given individual eat all food touching it */
    void eatNearbyFood (Individual & individual);

public:
    World world;
    SDLView sdlview;

    /** Constructs a World with the given parameters. They represent its dimension and max energy level */
    Controller(double WIDTH, double HEIGHT, double ENERGY);

     /** Adds objects to the world and prepares simulation. must be invoked before run() */
    void init();

    /** Starts the simulation. Runs as long as simulate returns true.
     *  Invokes applyAction() and update() for every Individual and their respective Action.
     *  Requires the Controller to be initialised.
     *  @return number of total iterations */
    long run();
};

#endif //EVE_CONTROLLER_H
