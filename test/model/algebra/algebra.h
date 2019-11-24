#ifndef EVE_ALGEBRA_H
#define EVE_ALGEBRA_H

#include <vector>

static std::vector<std::vector<Angle>> getAngles() {
    // 0 degrees ANGLES
    static std::vector<Angle> A;
    A.emplace_back(0.0);
    A.emplace_back(0);
    A.emplace_back(-360);
    A.emplace_back(360);
    A.emplace_back(720);
    A.emplace_back(2 * M_PI);


    // 90 degrees ANGLES
    static std::vector<Angle> B;
    B.emplace_back(0.5 * M_PI);
    B.emplace_back(90);
    B.emplace_back(450);
    B.emplace_back(-270);


    // 180 degrees ANGLES
    static std::vector<Angle> C;
    C.emplace_back(M_PI);
    C.emplace_back(180);
    C.emplace_back(-180);


    // 270 degrees ANGLES
    static std::vector<Angle> D;
    D.emplace_back(1.5 * M_PI);
    D.emplace_back(270);
    D.emplace_back(-90);


    static std::vector<std::vector<Angle>> ANGLES;
    ANGLES.push_back(A);
    ANGLES.push_back(B);
    ANGLES.push_back(C);
    ANGLES.push_back(D);

    return ANGLES;
}

#endif //EVE_ALGEBRA_H
