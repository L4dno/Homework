#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


int main() {

    int n = 0;
    std::cin >> n;

    std::vector<std::pair<int,int>> standings;

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    for (int i = 1; i <= n; ++i) {

        std::cin >> a >> b >> c >> d;
        standings.push_back({ a + b + c + d, i });
        std::stable_sort(standings.begin(), standings.end(),
            [](const std::pair<int, int> lhs, const std::pair<int, int> rhs)
            {return lhs.first > rhs.first; });

    }

    for (int i = 0; i < n; ++i) {
        if (standings[i].second == 1)
            std::cout << i + 1;
    }

    return 0;

}
