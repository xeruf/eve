//
// Created by aaron on 07/10/2019.
//

#ifndef EVE_POINT_H
#define EVE_POINT_H


struct Point {
    int x;
    int y;
    Point(int, int);
};

bool operator==(const Point &, const Point &);

#endif //EVE_POINT_H
