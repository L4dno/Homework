#include <iostream>
#include <vector>

int main() {

    int n = 0;
    std::cin >> n;

    std::vector<int> ans(n);
    
    int receiver = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> receiver;
        ans[receiver-1] = i;
    }

    for (int& i : ans)
        std::cout << i+1 << " ";

    return 0;

}