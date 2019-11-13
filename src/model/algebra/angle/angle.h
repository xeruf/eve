#ifndef EVE_ANGLE_H
#define EVE_ANGLE_H

#include "../algebra_conf.h"

#include <cmath>

struct Angle {
private:
    double a{};

    static double normalise (double angle);
    static int normalise (int angle);

public:
    explicit Angle (double angle);
    explicit Angle (int angle);

    [[nodiscard]] double radians() const;
    [[nodiscard]] int degrees() const;

    void update (double angle);
    void update (int angle);

    static double toRadians (int angle);
    static int toDegrees (double angle);
};

#endif //EVE_ANGLE_H
