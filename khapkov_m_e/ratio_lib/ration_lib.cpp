// ration_lib.cpp : Defines the entry point for the application.
//

#include "ration_lib.h"
#include <cassert>
#include <exception>

Ratio::Ratio(int num, int denom) :
    numerator(num), denominator(denom) {
    Reduce();

void Ratio::Test() {

    assert(GCD(3, 15) == 3);
    assert(GCD(7, 4) == 1);
    assert(GCD(3, 0) == 1);

    assert(GCD(denominator, numerator)==1);

}


void Ratio::Reduce() {

    if (denominator == 0) {
        throw std::divisi
    }

    int gcd = GCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

int Ratio::LCM(int lhs, int rhs) {
    return lhs * rhs / GCD(lhs, rhs);
}

int Ratio::GCD(int lhs, int rhs) {
    while (rhs != 0) {
        lhs %= rhs;
        std::swap(lhs, rhs);
    }
    return lhs;
}
