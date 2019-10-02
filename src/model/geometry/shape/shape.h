//
// Created by aaron on 02/10/2019.
//

#ifndef EVE_SHAPE_H
#define EVE_SHAPE_H

#include "../line/line.h"

#include <vector>

class Shape {
private:
    std::vector<Line> shape;
public:
    virtual std::vector<Line> getShape();
};


#endif //EVE_SHAPE_H
