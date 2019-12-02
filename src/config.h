#ifndef EVE_CONFIG_H
#define EVE_CONFIG_H

#define MIN_FOOD_SIZE 5.0
#define MAX_FOOD_SIZE 20.0
#define SURVIVAL_THRESHOLD MAX_FOOD_SIZE
#define VISION_RANGE 10.0
#define MOUTH_ANGLE 59

#define AMOUNT_OF_FREDS 10
#define AMOUNT_OF_PIERCIES 0

/* SDL RENDER PARAMETERS */
/** scaling of individuals and food for easier identification */
#define SCALE_FACTOR 3
/** delay between drawn frames in ms */
#define RENDER_DELAY 100

/* DEBUG CONSTANTS */
#define RENDER_TERMINALVIEW false
#define RENDER_SDLVIEW true

#endif //EVE_CONFIG_H
