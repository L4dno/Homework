#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

//const double EQ_EPS = std::numeric_limits<double>() * 2.0;
const double eps = 0.0001;

double Member(double x, int i) {
    int i_mod_2 = i % 2;
    int coef = 2 * i + 1;
    double x_pow = std::pow(x, coef);
    return (i_mod_2 ? -1 : 1) * x_pow / coef;
}

double Sum(double x) {
    int i = 0;
    double res = 0;
    double tmp = Member(x, i);
    while (std::abs(tmp) >= eps) {
        res += tmp;
        ++i;
        tmp = Member(x, i);
    }
    return res;
}

int main() {

    std::cout << std::fixed << std::setprecision(6);
    std::cout << std::setw(8);

    for (double x = 0.1; x <= 1.01; x += 0.05) {
        double sum = Sum(x);
        std::cout << x << " | " << sum << "\n";
    }

    return 0;

}