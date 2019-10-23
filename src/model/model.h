#ifndef EVE_MODEL_H
#define EVE_MODEL_H

struct Point {
    int x;
    int y;
    Point(int x, int y);
};

bool operator == (const Point &, const Point &);

#endif //EVE_MODEL_H
