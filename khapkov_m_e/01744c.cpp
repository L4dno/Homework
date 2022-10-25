#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//bool isGood(const std::vector<int>& greens, const int dist) {
//
//    for (int i = 1; i < greens.size(); ++i) {
//        if (greens[i] - greens[i - 1] - 1 > dist) {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int Solve() {
//
//    int n = 0;
//    char type = ' ';
//
//    std::cin >> n >> type;
//
//    std::string s;
//    s.reserve(n);
//    std::cin >> s;
//
//    std::vector<int> greens;
//    for (int i = 0; i < n; ++i) {
//        if (s[i] == 'g') {
//            greens.push_back(i);
//        }
//    }
//    greens.push_back(n + greens[0]);
//
//    int l = -1;
//    int r = s.size();
//    int m = 0;
//
//    while (r - l > 1) {
//        m = (r + l) / 2;
//
//        if (isGood(greens, m)) {
//            r = m;
//        }
//        else {
//            l = m;
//        }
//
//    }
//
//    return r;
//
//}

int Solve() {

    int n = 0;
    char type = ' ';
    std::cin >> n >> type;

    std::string s;
    s.reserve(n);
    std::cin >> s;

    if ('g' == type) {
        return 0;
    }

    int r = 0;
    int ans = -2e9;
    for (int l = 0; l < n; ++l) {

        while (r == l || 'g' != s[r % n]) {
            ++r;
        }

        if (s[l] == type) {
            ans = std::max(ans, r - l);
        }

    }

    return ans;

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        std::cout << Solve() << std::endl;
    }

    return 0;

}