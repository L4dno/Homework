#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int n = 0; 
    std::cin >> n;
    std::vector<int> a(n);
    for (int& i : a)
        std::cin >> i;

    std::vector<int> p(n + 1);
    for (int i = 0; i < n; ++i)
        p[i + 1] = p[i] + a[i];

    int m, worm = 0; std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> worm;
        std::cout << std::lower_bound(p.begin(), p.end(), worm) - p.begin() << "\n";
    }

    return 0;

}