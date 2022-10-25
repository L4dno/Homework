#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> CountSubLen(const std::string& text, const std::string& sample) {

    int n = text.size();
    int m = sample.size();

    std::vector<int> dp(n + 1);

    int j = 0;
    for (int i = 0; i < n; ++i) {

        if (j < m && text[i] == sample[j]) {
            dp[i + 1] = dp[i] + 1;
            j += 1;
        }
        else {
            dp[i + 1] = dp[i];
        }

    }

    return dp;

}

int main() {

    std::string s = "";
    std::cin >> s;

    std::string t = "";
    std::cin >> t;

    int n = s.size();
    int m = t.size();

    auto pref = CountSubLen(s, t);
    std::reverse(s.begin(), s.end());
    std::reverse(t.begin(), t.end());
    auto suff = CountSubLen(s, t);
    reverse(suff.begin(), suff.end());

    int r = 0;
    int ans = -2e9;

    for (int l = 0; l < n; ++l) {

        while (r < n && pref[l] + suff[r] >= m) {
            r += 1;
        }

        if (pref[l] + suff[r] >= m) {
            ans = std::max(ans, r - l);
        }
        else if (r > 0) {
            ans = std::max(ans, r - l - 1);
        }

    }

    std::cout << ans;

    return 0;

}