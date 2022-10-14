#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t; std::cin >> t;
    int n, k, pos, res, tmp; 
    std::string s, frbdn;


    while (t--) {

        std::cin >> n >> s >> k;
        pos = 0, res = 0;

        //O(1)
        frbdn.clear();
        frbdn.resize(n);
        for (int i = 0; i < k; ++i) {
            std::cin >> frbdn[i];
        }

        //O(n)
        tmp = s.find_first_of(frbdn, pos);
        while (tmp != -1) {
            res = std::max(res, tmp - pos);
            pos = tmp;
            tmp = s.find_first_of(frbdn, pos+1);
        }

        std::cout << res << "\n";

    }

    return 0;

}