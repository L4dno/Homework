#include <iostream>
#include <vector>

int main() {

    const int N = 6;
    std::vector<int> a(N);

    int sum = 0;
    for (int& in : a) {
        std::cin >> in;
        sum += in;
    }

    bool success = false;
    int tmp = 0;
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < N; ++j) 
            for (int k = 0; k < N; ++k) {
                if (i != j && j != k && i != k) {
                    tmp = a[i] + a[j] + a[k];
                    if (tmp == sum - tmp) {
                        success = true;
                        break;
                    }
                }
            }

    if (success)
        std::cout << "YES";
    else
        std::cout << "NO";

    return 0;

}