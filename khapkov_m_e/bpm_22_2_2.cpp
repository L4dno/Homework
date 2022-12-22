#include <iostream>
#include <cmath>
#include <iomanip>

bool Condition(double x, double y) {
    bool above_deg = (y >= std::abs(x));
    bool below_par = (y <= 2 - x * x);
    return above_deg && below_par;
}

int main() {

    double x = 0;
    double y = 0;
    double in = 0;
    double all = 0;
    
    while (std::cin >> x >> y) {
        if (Condition(x, y)) {
            in += 1;
        }
        all += 1;
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << in / all;

    return 0;

}