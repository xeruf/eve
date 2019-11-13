#include "angle.h"

Angle::Angle (double angle) : a{normalise(angle)} {}
Angle::Angle (int angle) : a{toRadians(normalise(angle))} {}

double Angle::normalise (double angle) {
    return (angle < 0) ? normalise(angle + 2 * M_PI) : fmod(angle, 2 * M_PI);
}
int Angle::normalise (int angle) {
    return (angle < 0) ? normalise(angle + 360) : angle % 360;
}

double Angle::radians() const {return a;}
int Angle::degrees() const {return toDegrees(a);}

void Angle::update (double angle) {a = angle;}
void Angle::update (int angle) {update(toRadians(angle));}

double Angle::toRadians (int angle) {return (double) angle / 180 * M_PI;}
int Angle::toDegrees (double angle) {return (int) round(angle / M_PI * 180);}


Angle & Angle::operator = (double val) {
    update(val);
    return * this;
}

double  Angle::operator - () const {return - a;}

double  Angle::operator +  (const Angle & angle) const {return a + angle.a;}
double  Angle::operator +  (double val)          const {return a + val;}

double  Angle::operator -  (const Angle & angle) const {return a - angle.a;}
double  Angle::operator -  (double val)          const {return a - val;}

double  Angle::operator *  (const Angle & angle) const {return a * angle.a;}
double  Angle::operator *  (double val)          const {return a * val;}

double  Angle::operator /  (const Angle & angle) const {return a / angle.a;}
double  Angle::operator /  (double val)          const {return a / val;}

bool    Angle::operator == (const Angle & angle) const {return a == angle.a;}
bool    Angle::operator == (double val)          const {return a == val;}

bool    Angle::operator <  (const Angle & angle) const {return a < angle.a;}
bool    Angle::operator <  (double val)          const {return a < val;}

bool    Angle::operator >  (const Angle & angle) const {return a > angle.a;}
bool    Angle::operator >  (double val)          const {return a > val;}

bool    Angle::operator ! () const {return not (bool) a;}
