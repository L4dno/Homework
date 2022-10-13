#include <vector>
#include <iostream>

void solve() {

    int n = 0;
    std::cin >> n;

    char c = ' ';
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;

    bool first = true;
    for (int i = 0; i < n*n; ++i) {

        std::cin >> c;

        if (c == '*') {
            if (first) {
                x1 = i / n;
                y1 = i % n;
            }
            else {
                x2 = i / n;
                y2 = i % n;
            }
            first = false;
        }

    }

    int x3 = 0;
    int x4 = 0;
    int y3 = 0;
    int y4 = 0;

    if (x1 == x2) {
        x3 = (x1 + 1)%n;
        x4 = (x1 + 1)%n;
        y3 = y1;
        y4 = y2;
    }
    else if (y1 == y2) {
        x3 = x1;
        x4 = x2;
        y3 = (y1 + 1)%n;
        y4 = (y1 + 1)%n;
    }
    else {
        x3 = x1;
        y3 = y2;
        x4 = x2;
        y4 = y1;
    }

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {

            if ((i == x1 || i == x2 || i == x3 || i == x4)
                && (j == y1 || j == y2 || j == y3 || j == y4))
                std::cout << '*';
            else
                std::cout << '.';

        }

        std::cout << std::endl;

    }

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t--) {

        //std::cout << std::endl;
        solve();
        //std::cout << std::endl;

    }

    return 0;

}