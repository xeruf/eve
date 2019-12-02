#ifndef EVE_OBJECT_H
#define EVE_OBJECT_H

#include "../algebra/algebra.h"

#include <vector>

/* Abstract base class for all objects in the world */
class Object {
protected:
    Point position;

public:
    Object(double x, double y);
    explicit Object(Point position);
    virtual ~Object() = 0;

    [[nodiscard]] Point getPosition() const;
};


#endif //EVE_OBJECT_H
