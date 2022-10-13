#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int solve() {

    int n = 0;
    std::cin >> n;

    std::vector<int> a(n);
    std::set <int> unique;

    int tmp = 0;
    for (int i = 0; i < n; ++i) {

        std::cin >> tmp;
        a[i] = tmp;
        unique.insert(tmp);

    }

    if (!unique.empty() && *unique.begin() == 0)
        return n - count(a.begin(), a.end(), 0);
    else if (unique.size() < n)
        return n;
    else
        return n + 1;

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t--) {

        std::cout << solve() << "\n";

    }

    return 0;

}