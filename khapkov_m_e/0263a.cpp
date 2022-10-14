#include <iostream>
#include <cmath>

int main() {

    int d = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cin >> d;
            if (d == 1) {
                x = i;
                y = j;
                break;
            }
        }
    }

    std::cout << std::abs(x - 2) + std::abs(y - 2);

    return 0;

}