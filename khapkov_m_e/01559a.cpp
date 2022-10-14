#include <iostream>

void solve() {

    int n = 0;
    std::cin >> n;

    int res = (1<<31)-1;
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        res &= tmp;
    }

    std::cout << res << std::endl;

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t--) {

        solve();

    }

    return 0;

}