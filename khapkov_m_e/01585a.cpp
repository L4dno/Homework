#include <iostream>
#include <vector>

int Solve() {

    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);

    for (int& i : a)
        std::cin >> i;

    int count = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            if (i < n - 1) {
                if (a[i + 1] == 0) {
                    return -1;
                }

            }
        }
        if (a[i] == 1) {
            count += 1;
            if (i < n - 1)
                if (a[i + 1] == 1)
                    count += 4;
        }
    }

    if (count >= 1)
        return count;

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        std::cout << Solve() << "\n";
    }

    return 0;

}