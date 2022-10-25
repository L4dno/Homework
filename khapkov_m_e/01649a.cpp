#include <iostream>
#include <vector>
#include <algorithm>

int CountPref(const std::vector<int>& a) {
    int ans = 0;
    for (int i : a) {
        if (i) {
            ++ans;
        }
        else {
            return ans;
        }
    }
    return ans;
}

int Solve() {

    int n = 0;
    std::cin >> n;

    std::vector<int> a(n);
    for (int& i : a)
        std::cin >> i;

    int reachable = CountPref(a);
    std::reverse(a.begin(), a.end());
    reachable += CountPref(a);

    return std::max(n - reachable + 1,0);

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        std::cout<<Solve()<<"\n";
    }

    return 0;

}