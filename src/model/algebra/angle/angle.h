#ifndef EVE_ANGLE_H
#define EVE_ANGLE_H

#include "../algebra_conf.h"

#include <cmath>

/** A wrapper around doubles to store angles in. It is guaranteed to be within [0; 2xPI) */
struct Angle {
private:
    double a;

    /** A static normaliser converting an angle given in radians to one within [0; 2xPI) */
    static double normalise (double angle);
    /** A static normaliser converting an angle given in degrees to one within [0; 360) */
    static int normalise (int angle);

public:
    /** Constructs a proper Angle from one given in radians */
    explicit Angle (double angle);
    /** Constructs a proper Angle from one given in degrees */
    explicit Angle (int angle);

    /** Returns this Angle in radians */
    [[nodiscard]] double radians() const;
    /** Returns this Angle in degrees */
    [[nodiscard]] int degrees() const;

    /** Sets this Angle to the one given */
    Angle & update (const Angle & angle);
    /** Sets this Angle to one given in radians */
    Angle & update (double angle);
    /** Sets this Angle to one given in degrees */
    Angle & update (int angle);

    /** Returns the difference between the two Angles */
    [[nodiscard]] double angleTo (const Angle & angle) const;

    /** A static converter of an Angle from degrees to radians */
    static double toRadians (int angle);
    /** A static converter of an Angle from radians to degrees */
    static int toDegrees (double angle);

    /** Returns an Angle in the opposite direction */
    Angle operator -() const;

    /** Sets this Angle to the one given in radians */
    Angle & operator = (double val);
    /** Sets this Angle to the one given */
    Angle & operator = (const Vector & v);

    /** Adds the Angle given onto this one */
    Angle & operator += (const Angle & angle);
    /** Subtracts the Angle given from this one */
    Angle & operator -= (const Angle & angle);

    /** Returns the sum of both Angles given */
    Angle operator +  (const Angle & angle) const;
    /** Returns the sum of both Angles given */
    Angle operator +  (double val)          const;

    /** Returns the difference of both Angles given */
    Angle operator -  (const Angle & angle) const;
    /** Returns the difference of both Angles given */
    Angle operator -  (double val)          const;

    /** Returns the product of both Angles given */
    Angle operator *  (const Angle & angle) const;
    /** Returns the product of both Angles given */
    Angle operator *  (double val)          const;

    /** Returns the quotient of both Angles given */
    Angle operator /  (const Angle & angle) const;
    /** Returns the quotient of both Angles given */
    Angle operator /  (double val)          const;

    /** Checks whether the direction of the given Vector has this Angle */
    bool  operator == (const Vector & vec)  const;
    /** Compares the two Angles given */
    bool  operator == (const Angle & angle) const;
    /** Compares the two Angles given */
    bool  operator == (double val)          const;

    /** Checks whether the direction of the given Vector is different to this Angle */
    bool  operator != (const Vector & vec)  const;
    /** Checks whether both Angles given differ from each other */
    bool  operator != (const Angle & angle) const;
    /** Checks whether both Angles given differ from each other */
    bool  operator != (double val)          const;

    /** Checks if this Angle is bigger or equals than the direction of the given Vector */
    bool  operator >= (const Vector & vec)  const;
    /** Checks whether this Angle is bigger or equals than the one given */
    bool  operator >= (const Angle & angle) const;
    /** Checks whether this Angle is bigger or equals than the one given */
    bool  operator >= (double val)          const;

    /** Checks if this Angle is smaller or equals than the direction of the given Vector */
    bool  operator <= (const Vector & vec)  const;
    /** Checks whether this Angle is smaller or equals than the one given */
    bool  operator <= (const Angle & angle) const;
    /** Checks whether this Angle is smaller or equals than the one given */
    bool  operator <= (double val)          const;

    /** Checks if this Angle is smaller than the direction of the given Vector */
    bool  operator <  (const Vector & vec)  const;
    /** Checks whether this Angle is smaller than the one given */
    bool  operator <  (const Angle & angle) const;
    /** Checks whether this Angle is smaller than the one given */
    bool  operator <  (double val)          const;

    /** Checks if this Angle is bigger than the direction of the given Vector */
    bool  operator >  (const Vector & vec)  const;
    /** Checks whether this Angle is bigger than the one given */
    bool  operator >  (const Angle & angle) const;
    /** Checks whether this Angle is bigger than the one given */
    bool  operator >  (double val)          const;
};

#endif //EVE_ANGLE_H
