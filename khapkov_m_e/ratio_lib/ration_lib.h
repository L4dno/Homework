// ration_lib.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.

class Ratio {

public:

    Ratio() = default;
    Ratio(int num, int denom);
    explicit Ratio(double fraction);

    bool operator==(const Ratio rhs) const;
    bool operator!=(const Ratio rhs) const;

    Ratio& operator+=(const Ratio rhs);
    Ratio& operator-=(const Ratio rhs);
    Ratio& operator*=(const Ratio rhs);
    Ratio& operator/=(const Ratio rhs);

    void Test();

private:

    void Reduce();

    int LCM(int lhs, int rhs);
    int GCD(int lhs, int rhs);

    int numerator = 0;
    int denominator = 1;

    //static const double eps = 1e-7;

};
