#include <iostream>
#include <string>
#include <algorithm>

int Solve() {

    std::string seq = " ";
    std::cin >> seq;

    int i_last_one = seq.rfind('1');
    int i_first_zero = seq.find('0');
    int n = seq.size();

    if (i_last_one == -1 && i_first_zero == -1) {
        return n;
    }
    if (i_last_one == -1) {
        return i_first_zero + 1;
    }
    if (i_first_zero == -1) {
        return n - i_last_one;
    }
    return i_first_zero - i_last_one + 1;

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        std::cout<<Solve()<<std::endl;
    }

    return 0;

}