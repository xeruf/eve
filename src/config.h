#ifndef EVE_CONFIG_H
#define EVE_CONFIG_H

#define MIN_FOOD_SIZE 200.0
#define MAX_FOOD_SIZE 500.0

#define SURVIVAL_THRESHOLD MAX_FOOD_SIZE
#define INDIVIDUAL_START_SIZE 5 * SURVIVAL_THRESHOLD
#define REPRODUCTION_THRESHOLD 20 * SURVIVAL_THRESHOLD
#define REPRODUCTION_CHILD_FRACTION 0.3

#define VISION_RANGE 30
#define MOUTH_ANGLE 59

/* Action constants */
#define FRICTION 0.3
#define TURN_RATE 3
#define MOVE_RATE 3

/* Action multiplier */
#define ACTION_FACTOR_MOVE -0.0002
#define ACTION_FACTOR_TURN -0.0001

/* Energy consumption multiplier per action */
#define IDLE_ENERGY_USE 0.0004
#define TURN_COST       3
#define MOVE_COST       10

/* SDL RENDER PARAMETERS */
/** scaling of individuals and food for easier identification */
#define SCALE_FACTOR 1
/** delay between drawn frames in ms */
#define RENDER_DELAY 10

/* DEBUG CONSTANTS */
#define RENDER_TERMINALVIEW false
#define RENDER_SDLVIEW true

#define AMOUNT_OF_FREDS    8
#define AMOUNT_OF_BRANDIES 8
#define AMOUNT_OF_PIERCIES 0

/* COLOR constants */
#define POINTER_COLOR    0xAAAAAAAA
#define BACKGROUND_COLOR 0xFF000000
#define FOOD_COLOR       0xFF0000FF
#define INDIVIDUAL_COLOR 0xFF00FFFF
#define FRED_COLOR       0xFF22FFFF
#define BRANDY_COLOR     0xFFFFFF00
#define PIERCY_COLOR     0xFFFF00FF

#define COLOR_CHANGE_FRACTION 0.2

#define PREALLOCATED_OBJECTS 10000

#endif //EVE_CONFIG_H
