#include <iostream>

void Solve() {

    int n = 0;
    int q = 0;
    std::cin >> n >> q;

    long long sum = 0;
    int odd_cnt = 0;
    int even_cnt = 0;
    
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        sum += tmp;
        if (0 == tmp % 2) {
            even_cnt += 1;
        }
        else {
            odd_cnt += 1;
        }
    }

    int type = 0;
    long long x = 0;
    for (int i = 0; i < q; ++i) {
        std::cin >> type >> x;

        if (0 == x % 2) {
            if (0 == type) {
                sum += even_cnt * x;
            }
            else {
                sum += odd_cnt * x;
            }
        }

        else {
            if (0 == type) {
                sum += even_cnt * x;
                odd_cnt += even_cnt;
                even_cnt = 0;
            }
            else {
                sum += odd_cnt * x;
                even_cnt += odd_cnt;
                odd_cnt = 0;
            }
        }

        std::cout << sum << std::endl;

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