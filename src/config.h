#ifndef EVE_CONFIG_H
#define EVE_CONFIG_H

/* Food size constants. Individuals scale with food (See INDIVIDUAL_START_SIZE) */
/// Minimum size of a food object. Set very small for lots of small particles or big for large chunks
#define MIN_FOOD_SIZE 400.0
/// Maximum food size. Guess what happens...
#define MAX_FOOD_SIZE 1000.0

/* These parameters determine thresholds for individuals */
/// Individuals with less energy than this die
#define SURVIVAL_THRESHOLD MAX_FOOD_SIZE
/// Individuals initially start with this amount of energy
#define INDIVIDUAL_START_SIZE 5 * SURVIVAL_THRESHOLD
/// Surpassing this threshold leads to asexual reproduction
#define REPRODUCTION_THRESHOLD 20 * SURVIVAL_THRESHOLD
/// Offspring take this percentage of energy from their parent
#define REPRODUCTION_CHILD_FRACTION 0.3

/* Vision parameters for individuals. The vision is a cone starting from their core */
/// Radius of the cone. Displayed as a grey line
#define VISION_RANGE 200
/// Angle. Imagine Pacman (We want to render them like that later)
#define MOUTH_ANGLE 59

/* Action constants */
/// We work with kinetic. Kinetical energy decays by *this* much every turn
#define FRICTION 0.2
/// The speed by which they turn. Set high for disks spinning uncontrolledly
#define TURN_RATE 3
/// The speed by which they move. Higher values makes them faster, lower ones let them starve.
#define MOVE_RATE 3

/* Action multiplier */
/// Multiplied with individual's size - This basically determines their inertia
#define ACTION_FACTOR_MOVE -0.00005
/// Same as above; higher values mean that larger entities rotate slower
#define ACTION_FACTOR_TURN -0.00001

/* Energy consumption multiplier per action */
/// Energy use if individual does nothing
#define IDLE_ENERGY_USE 0.001
/// Energy use if individual turns
#define TURN_COST       2
/// Energy use if individual moves
#define MOVE_COST       8

/* SDL RENDER PARAMETERS */
/// Scaling of individuals and food for easier identification.
/// This does not change hit boxes and vision ranges; it's purely cosmetical
#define SCALE_FACTOR 1
/// Delay between drawn frames in ms
#define RENDER_DELAY 10

/* VIEWS */
/// Initial view, terminal-rendered. Used only for debugging; best left disabled
#define RENDER_TERMINALVIEW false
/// Graphical view
#define RENDER_SDLVIEW true

/** Specify the how many of each species to spawn initially */
/// Species with very basic reinforcement learning:
#define AMOUNT_OF_FREDS    0
/// Species choosing random actions each turn:
#define AMOUNT_OF_BRANDIES 0
/// Player-controlled species. This one doesn't work yet and will just stay idle
#define AMOUNT_OF_PIERCIES 0
/// Species using basic reinforcement learning and its vision range
#define AMOUNT_OF_DEISIES  8

/* COLOR constants */
/** IMPORTANT: All colors are in 0xAABBGGRR:
 * A: Brightness
 * B: Blue
 * G: Green
 * R: Red
 */
#define POINTER_COLOR    0xAAAAAAAA
#define BACKGROUND_COLOR 0xFF000000
#define FOOD_COLOR       0xFF0000FF
#define INDIVIDUAL_COLOR 0xFF00FFFF
#define FRED_COLOR       0xFF22FFFF
#define BRANDY_COLOR     0xFFFFFF00
#define PIERCY_COLOR     0xFFFF00FF
#define DEISY_COLOR      0xFFFF00FF

/* Deisy has seven different natures determining its behaviour */
/// Disable the default color for deisy and color it by nature instead:
#define COLOR_BY_NATURE true

/// Color for a lustful deisy:
#define CLUST       0xFF6000FF                  /// LUST     = RED
/// Color for a gluttonous deisy:
#define CGLUTTONY   0xFF00A5FF                  /// GLUTTONY = ORANGE
/// Color for a greedy deisy:
#define CGREED      0xFF00FFD0                  /// GREED    = YELLOW
/// Color for a slothful deisy:
#define CSLOTH      0xFF00FF00                  /// SLOTH    = GREEN
/// Color for a wrathsome deisy:
#define CWRATH      0xFFFFB000                  /// WRATH    = BLUE
/// Color for an envious deisy:
#define CENVY       0xFF82004B                  /// ENVY     = INDIGO
/// Color for a proud deisy:
#define CPRIDE      0xFFFF007F                  /// PRIDE    = VIOLET

/// Children are *this* much darker than their parents
#define COLOR_CHANGE_FRACTION 0.2

/// Used for faster allocation by preallocating some bytes:  [NOT IN USE]
#define PREALLOCATED_OBJECTS 10000

#endif //EVE_CONFIG_H
