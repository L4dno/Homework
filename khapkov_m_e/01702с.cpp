#include <iostream>
#include <map>
#include <utility>

void Solve() {

    int n = 0;
    int k = 0;
    std::cin >> n >> k;

    std::map<int, std::pair<int,int>> entry;

    for (int i = 1, tmp = 0; i <= n; ++i) {
        std::cin >> tmp;
        if (entry.find(tmp) == entry.end()) {
            entry[tmp] = { i,i };
        }
        else {
            entry[tmp].second = i;
        }
    }

    for (int i = 0, a = 0, b = 0; i < k; ++i) {
        std::cin >> a >> b;
        if (entry[a].first != 0 && entry[b].second != 0
            && entry[a].first < entry[b].second)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
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