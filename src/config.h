#ifndef EVE_CONFIG_H
#define EVE_CONFIG_H

#define MIN_FOOD_SIZE 100.0
#define MAX_FOOD_SIZE 400.0
#define INDIVIDUAL_FOOD_FACTOR 5.0
#define SURVIVAL_THRESHOLD MAX_FOOD_SIZE
#define REPRODUCTION_THRESHOLD 10 * SURVIVAL_THRESHOLD
#define REPRODUCTION_CHILD_FRACTION 0.2
#define VISION_RANGE 30
#define MOUTH_ANGLE 59

/* Action constants */
#define FRICTION 0.3
#define TURN_RATE 5
#define MOVE_RATE 5

/* Action multiplier */
#define ACTION_FACTOR_MOVE 0.0001
#define ACTION_FACTOR_TURN 0.0001

/* Energy consumption multiplier per action */
#define ENERGY_FACTOR_SLEEP 0.995
#define ENERGY_FACTOR_TURN  0.997 * ENERGY_FACTOR_SLEEP
#define ENERGY_FACTOR_MOVE  0.995 * ENERGY_FACTOR_SLEEP

/* SDL RENDER PARAMETERS */
/** scaling of individuals and food for easier identification */
#define SCALE_FACTOR 1
/** delay between drawn frames in ms */
#define RENDER_DELAY 10

/* DEBUG CONSTANTS */
#define RENDER_TERMINALVIEW false
#define RENDER_SDLVIEW true

#define AMOUNT_OF_FREDS 0
#define AMOUNT_OF_BRANDIES 20
#define AMOUNT_OF_PIERCIES 0

/* COLOR constants */
#define POINTER_COLOR    0xFFAAAAAA
#define BACKGROUND_COLOR 0xFF333300
#define INDIVIDUAL_COLOR 0xFF22FFFF
#define FOOD_COLOR       0xFF00BB00

#endif //EVE_CONFIG_H
