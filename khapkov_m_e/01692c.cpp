#include <iostream>

void Solve() {

    const int n = 8;

    char symb = ' ';
    int line_cnt = 0;
    int x = 0;
    int y = 0;
    int prev_cnt = 0;

    bool flag = false;
    for (int i = 0; i < n; ++i) {

        line_cnt = 0;
        for (int j = 0; j < n; ++j) {

            std::cin >> symb;
            if (symb == '#') {

                if (0 == line_cnt && !flag) {
                    x = i + 1;
                    y = j + 1;
                }
                ++line_cnt;
            }

        }

        if (2 == prev_cnt && 1 == line_cnt) {
            flag = true;
        }
        prev_cnt = line_cnt;

    }

    std::cout << x << " " << y << std::endl;

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        Solve();
    }

    return 0;

}