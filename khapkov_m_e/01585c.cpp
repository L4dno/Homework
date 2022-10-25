#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

long long CountDist(const std::vector<int>& road, bool should_return, const int k) {

    int n = road.size();
    n -= 1;
    long long sum = 0;

    bool is_first = true;
    while (n >= 0) {
        if (is_first && !should_return) {
            sum += road[n];
            n -= k;
            is_first = false;
        }
        else {
            sum += road[n] * 2;
            n -= k;
        }
    }

    return sum;

}

long long Solve() {

    int n = 0;
    int k = 0;
    std::cin >> n >> k;

    std::vector<int> negatives;
    std::vector<int> positives;

    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        if (tmp < 0) {
            negatives.push_back(tmp * -1);
        }
        else {
            positives.push_back(tmp);
        }
    }
    std::sort(positives.begin(), positives.end());
    std::sort(negatives.begin(), negatives.end());

    if (!positives.empty() && !negatives.empty()) {
        bool is_pos_bigger = positives.back() > negatives.back();
        return CountDist(positives, !is_pos_bigger, k) + 
            CountDist(negatives, is_pos_bigger, k);
    }
    else if (!positives.empty()) {
        return CountDist(positives, false, k);
    }
    else {
        return CountDist(negatives, false, k);
    }

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        std::cout << Solve() << std::endl;
    }

    return 0;

}