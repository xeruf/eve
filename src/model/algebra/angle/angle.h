#ifndef EVE_ANGLE_H
#define EVE_ANGLE_H

#include "../algebra_conf.h"

#include <cmath>

/* Guaranteed to be between 0 and 2 PI */
struct Angle {
private:
    double a;

    static double normalise (double angle);
    static int normalise (int angle);

public:
    explicit Angle (double angle);
    explicit Angle (int angle);

    [[nodiscard]] double radians() const;
    [[nodiscard]] int degrees() const;

    Angle & update (const Angle & angle);
    Angle & update (double angle);
    Angle & update (int angle);

    [[nodiscard]] double angleTo (const Angle & angle) const;

    static double toRadians (int angle);
    static int toDegrees (double angle);

    /* Overloaded operators */
    Angle & operator = (double val);
    Angle & operator = (const Vector & v);

    Angle operator - () const;

    Angle operator +  (const Angle & angle) const;
    Angle operator +  (double val)          const;

    Angle operator -  (const Angle & angle) const;
    Angle operator -  (double val)          const;

    Angle operator *  (const Angle & angle) const;
    Angle operator *  (double val)          const;

    Angle operator /  (const Angle & angle) const;
    Angle operator /  (double val)          const;

    bool  operator == (const Vector & vec)  const;
    bool  operator == (const Angle & angle) const;
    bool  operator == (double val)          const;

    bool  operator != (const Vector & vec)  const;
    bool  operator != (const Angle & angle) const;
    bool  operator != (double val)          const;

    bool  operator >= (const Vector & vec)  const;
    bool  operator >= (const Angle & angle) const;
    bool  operator >= (double val)          const;

    bool  operator <= (const Vector & vec)  const;
    bool  operator <= (const Angle & angle) const;
    bool  operator <= (double val)          const;

    bool  operator <  (const Vector & vec)  const;
    bool  operator <  (const Angle & angle) const;
    bool  operator <  (double val)          const;

    bool  operator >  (const Vector & vec)  const;
    bool  operator >  (const Angle & angle) const;
    bool  operator >  (double val)          const;
};

#endif //EVE_ANGLE_H
