#include <iostream>
#include <vector>
#include <algorithm>

struct Ind{
    int ind = 0;
    int twos = 0;
};

bool operator<(const Ind lhs, const Ind rhs) {
    return lhs.twos < rhs.twos;
}

inline int Count(int n) {

    int res = 0;
    while (0==n % 2) {
        res += 1;
        n /= 2;
    }

    return res;

}

int Solve(const std::vector<Ind>& twos) {

    int n = 0;
    std::cin >> n;

    int delta = n;
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        delta -= Count(tmp);
    }

    if (delta<=0) {
        return 0;
    }

    int opers = 0;
    for (auto [i, cnt] : twos) {
        if (i <= n && delta>0) {
            delta -= cnt;
            opers += 1;
        }
    }

    if (delta > 0) {
        return -1;
    }
    return opers;

}

int main() {

    const int N = 2e5 + 1;
    std::vector<Ind> two_cnt(N);

    for (int i = 1; i < N; ++i) {
        two_cnt[i].twos = Count(i);
        two_cnt[i].ind = i;
    }

    std::sort(two_cnt.begin(), two_cnt.end());
    std::reverse(two_cnt.begin(), two_cnt.end());

    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        std::cout << Solve(two_cnt) << std::endl;
    }

    return 0;

}