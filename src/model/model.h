#ifndef EVE_MODEL_H
#define EVE_MODEL_H

#include <cmath>

#define CONST_MODIFIER 1000

struct Point;
struct Vector;

struct Point {
    double x;
    double y;
    Point (double x, double y);

    Point & operator = (const Vector & v);

    bool operator == (const Point & p) const;

    /** Returns the distance between the two points */
    double operator / (const Point & p) const;

    Point operator + (const Point & p) const;
    Point operator + (const Vector & v) const;

    Point operator - (const Point & p) const;
    Point operator - (const Vector & v) const;

    /** Operators to calculate the vector between two points */
    Vector operator >= (const Point & p) const;
    Vector operator <= (const Point & p) const;

    [[nodiscard]] bool withinCone(const Point & origin, const Vector & center, double angle) const;
};

struct Vector {
    double angle;
    double length;

    explicit Vector (Point p);
    Vector (double angle, double length);
    Vector (int angle, double length);

    Vector & operator = (const Point & p);

    /** Compares 'this' with ORIGIN >= p */
    bool operator == (const Point & p) const;
    bool operator == (const Vector & v) const;

    Vector operator + (const Vector & v) const;

    Vector operator - () const;
    Vector operator - (const Vector & v) const;
};

struct Angle {
private:
    double a{};

    static double normalise (double angle);
    static int normalise (int angle);

public:
    explicit Angle (const Vector & v);
    explicit Angle (double angle);
    explicit Angle (int angle);

    [[nodiscard]] double radians() const;
    [[nodiscard]] int degrees() const;

    void update (double angle);
    void update (int angle);

    static double toRadians (int angle);
    static int toDegrees (double angle);
};

static const Point ORIGIN = Point(0, 0);

#endif //EVE_MODEL_H
