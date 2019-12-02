#ifndef EVE_CONFIG_H
#define EVE_CONFIG_H

#define MIN_FOOD_SIZE 50.0
#define MAX_FOOD_SIZE 200.0
#define INDIVIDUAL_FOOD_FACTOR 5.0
#define SURVIVAL_THRESHOLD MAX_FOOD_SIZE
#define VISION_RANGE 20.0
#define MOUTH_ANGLE 59

/* Energy consumption multiplier per action */
#define SLEEP_FACTOR 0.995
#define  MOVE_FACTOR 0.975
#define  TURN_FACTOR 0.98

/* SDL RENDER PARAMETERS */
#define SCALE_FACTOR 1      // scaling of individuals and food for easier identification
#define RENDER_DELAY 10     // delay between drawn frames in ms

/* DEBUG CONSTANTS */
#define RENDER_TERMINALVIEW false
#define RENDER_SDLVIEW true

#define AMOUNT_OF_FREDS 20
#define AMOUNT_OF_PIERCIES 0

#endif //EVE_CONFIG_H
