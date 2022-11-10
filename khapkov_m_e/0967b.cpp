#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int n = 0;
    double a = 0;
    double b = 0;
    std::cin >> n >> a >> b;

    double first = 0;
    std::cin >> first;

    std::vector<double> v(n - 1);
    double sum = first;
    for (double& i : v) {
        std::cin >> i;
        sum += i;
    }

    std::sort(v.begin(), v.end(), [](const double& lhs,
        const double& rhs) { return lhs > rhs; });

    int i = 0;
    const double edge = b / a;
    double tmp = first / sum;
    while ((edge > tmp) && (i < n - 1)) {
        sum -= v[i];
        tmp = first / sum;
        ++i;
    }

    std::cout << i;

    return 0;

}