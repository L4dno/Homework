#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

const int indent = 10;

double fact(const int n) {
    if (!n)
        return 1;
    return n * fact(n - 1);
}

double member(const double x, const int i) {
    double num = pow(x * 2, i);
    double denum = fact(i);
    double res = num / denum;

    return res;

}

double f(const double x) {
    return pow(M_E, 2*x);
}

double s(const double x, const double eps) {

    double tmp = 0;
    double res = 0;

    for (int i = 0;; ++i) {
        tmp = member(x, i);
        if (std::abs(tmp) < eps)
            break;
        res += tmp;
    }

    return res;

}

void print(const double x, const double s, const double y) {

    std::cout << std::endl;
    std::cout << std::setw(indent) << x << "|";
    std::cout << std::setw(indent) << s << "|";
    std::cout << std::setw(indent) << y << "|";

}

void head() {
    std::cout << std::fixed;

    std::cout << std::setw(indent) << 'x' << "|";
    std::cout << std::setw(indent) << "s(x)" << "|";
    std::cout << std::setw(indent) << "f(x)" << "|";
}

int main() {

    const double a = 0;
    const double b = 1;
    const double d = 0.1;
    const double eps = 1e-4;

    head();

    for (double x = a; x <= b; x += d)
        print(x, s(x, eps), f(x));

    return 0;

}