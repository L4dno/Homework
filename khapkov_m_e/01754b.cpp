#include <iostream>

void Solve() {

    int n = 0;
    std::cin >> n;

    bool is_even = (n % 2 == 0);
    int half = (n+1) / 2;

    while (half > 0) {
        std::cout << half << " ";
        if (half > 1 || is_even) {
            std::cout << n << " ";
        }
        half -= 1;
        n -= 1;
    }
    std::cout << std::endl;

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        Solve();
    }

    return 0;

}