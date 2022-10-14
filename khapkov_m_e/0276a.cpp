#include <iostream>
#include <algorithm>

int main() {
    
    int n = 0;
    int k = 0;
    std::cin >> n >> k;

    int ans = -2e9;
    int f = 0;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> f >> t;
        if (t > k) {
            ans = std::max(ans, f - t + k);
       }
        else {
            ans = std::max(ans, f);
        }
    }

    std::cout << ans;

    return 0;

}