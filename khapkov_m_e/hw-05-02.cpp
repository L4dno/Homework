#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

const int indent = 10;

double member(double x, int i) {
    double num = pow(x, i);
    double denum = sin(i*M_PI/4);
    double res = num * denum;

    return res;
}

double f(double x) {
    double spi = sin(M_PI / 4.0);
    double cpi = cos(M_PI / 4.0);

    double num = x * spi;
    double denum = 1.0 - 2 * x * cpi;
    
    return num / denum;
}

double s(double x, const double eps) {

    double tmp = 0;
    double res = 0;

    for (int i = 1;; ++i) {
        if (i % 4 == 0)
            continue;
        tmp = member(x, i);
        if (std::abs(tmp) < eps)
            break;
        res += tmp;
    }

    return res;

}

void print(double x, double s, double y) {

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
    const double d = 0.05;
    const double eps = 1e-3;

    head();

    for (double x = a; x <= b; x += d)
        print(x, s(x, eps), f(x));

    return 0;

}