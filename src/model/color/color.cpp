#include "color.h"

int darken (unsigned int color) {
    return darken (color, COLOR_CHANGE_FRACTION);
}

int darken (unsigned int color, double fraction) {
    auto c = (unsigned char *) & color;
    for (int i = 0; i < 3; i++) {
        c[i] = (char) floor (c[i] * (1 - fraction));
    }
    return * (unsigned int *) c;
}