#include <iostream>
#include <algorithm>

int main() {

    int n = 0;
    int k = 0;
    std::cin >> n >> k;

    int a = 0;
    int ans = 2e9;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        if (k % a == 0) {
            ans = std::min(ans, k / a);
        }
    }

    std::cout << ans;

    return 0;

}