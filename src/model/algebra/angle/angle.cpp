#include "angle.h"
#include "../algebra.h"

Angle::Angle (double angle) :
    a{normalise (angle)} {}

Angle::Angle (int angle) :
    a{toRadians (normalise (angle))} {}


double Angle::normalise (double angle) {
    return (angle < 0) ? normalise (angle + 2 * M_PI) : fmod (angle, 2 * M_PI);
}
int Angle::normalise (int angle) {
    return (angle < 0) ? normalise (angle + 360) : angle % 360;
}

double Angle::radians() const {return a;}
int Angle::degrees() const {return toDegrees (a);}

Angle & Angle::update (const Angle & angle) {
    * this = angle;
    return * this;
}
Angle & Angle::update (double angle) {
    a = normalise (angle);
    return * this;
}
Angle & Angle::update (int angle) {return update (toRadians (angle));}

double Angle::angleTo (const Angle & angle) const {
    double distance = fabs (a - angle.radians());
    return (distance > M_PI) ? distance - M_PI : distance;
}

double Angle::toRadians (int angle) {return normalise ( (double) angle / 180 * M_PI);}
int Angle::toDegrees (double angle) {return normalise ( (int) round (angle / M_PI * 180));}


Angle & Angle::operator = (double val) {
    update (val);
    return * this;
}
Angle & Angle::operator = (const Vector & v) {
    update (v.angle);
    return * this;
}

Angle & Angle::operator += (const Angle & angle) {
    return * this = * this + angle;
}
Angle & Angle::operator -= (const Angle & angle) {
    return * this = * this - angle;
}

Angle Angle::operator -() const {return Angle (- a);}

Angle Angle::operator +  (const Angle & angle) const {return Angle (a + angle.a);}
Angle Angle::operator +  (double val)          const {return Angle (a + val);}

Angle Angle::operator -  (const Angle & angle) const {return Angle (a - angle.a);}
Angle Angle::operator -  (double val)          const {return Angle (a - val);}

Angle Angle::operator *  (const Angle & angle) const {return Angle (a * angle.a);}
Angle Angle::operator *  (double val)          const {return Angle (a * val);}

Angle Angle::operator /  (const Angle & angle) const {return Angle (a / angle.a);}
Angle Angle::operator /  (double val)          const {return Angle (a / val);}

bool  Angle::operator == (const Vector & vec)  const {return * this == vec.angle;}
bool  Angle::operator == (const Angle & angle) const {return coarseEquals (a, angle.a);}
bool  Angle::operator == (double val)          const {return coarseEquals (a, val);}

bool  Angle::operator != (const Vector & vec)  const {return * this != vec.angle;}
bool  Angle::operator != (const Angle & angle) const {return !coarseEquals (a, angle.a);}
bool  Angle::operator != (double val)          const {return !coarseEquals (a, val);}

bool  Angle::operator >= (const Vector & vec)  const {return * this >= vec.angle;}
bool  Angle::operator >= (const Angle & angle) const {return * this > angle || * this == angle;}
bool  Angle::operator >= (double val)          const {return * this > val || * this == val;}

bool  Angle::operator <= (const Vector & vec)  const {return * this <= vec.angle;}
bool  Angle::operator <= (const Angle & angle) const {return * this < angle || * this == angle;}
bool  Angle::operator <= (double val)          const {return * this < val || * this == val;}

bool  Angle::operator <  (const Vector & vec)  const {return * this < vec.angle;}
bool  Angle::operator <  (const Angle & angle) const {return normalise (a < angle.a);}
bool  Angle::operator <  (double val)          const {return normalise (a < val);}

bool  Angle::operator >  (const Vector & vec)  const {return * this > vec.angle;}
bool  Angle::operator >  (const Angle & angle) const {return normalise (a > angle.a);}
bool  Angle::operator >  (double val)          const {return normalise (a > val);}

