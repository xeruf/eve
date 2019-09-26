//
// Created by aaron on 26/09/2019.
//

#ifndef EVE_MODEL_H
#define EVE_MODEL_H

struct Point {
    int x;
    int y;
    Point(int, int);
};

bool operator==(const Point &, const Point &);

#endif //EVE_MODEL_H
