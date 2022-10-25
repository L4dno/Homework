#include <iostream>
#include <cmath>

void yes() {
    std::cout << "YES" << std::endl;
}

void no() {
    std::cout << "NO" << std::endl;
}

void Solve() {

    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    char state = ' ';
    int x_up = -1;
    int y_up = -1;
    int x_left = -1;
    int y_left = -1;

    for (int i = 0; i < n; ++i) {
        
        for (int j = 0; j < m; ++j) {
            std::cin >> state;

            if (state == 'R') {

                if (-1 == x_up) {
                    x_up = i;
                    y_up = j;
                }

                if (-1 == y_left || y_left > j) {
                    x_left = i;
                    y_left = j;
                }

            }
        }

    }

    if (x_left > x_up || y_up > y_left) {
        no();
    }
    else {
        yes();
    }

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        Solve();
    }

    return 0;

}