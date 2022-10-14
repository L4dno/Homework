#include <iostream>
#include <vector>

void solve() {

    int n = 0;
    std::cin >> n;

    std::vector<int> ans;

    int dig = 0;
    int mul = 1;
    while (n) {

        dig = n % 10;
        if (dig) {
            ans.push_back(dig * mul);
        }
        n /= 10;
        mul *= 10;

    }
    std::cout << ans.size() << std::endl;
    for (int i : ans)
        std::cout << i << " ";
    std::cout << std::endl;

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;

}