#include "color.h"

int darken (int color) {
    return darken (color, COLOR_CHANGE_FRACTION);
}

int darken (int color, double fraction) {
    return color - color * fraction;
}