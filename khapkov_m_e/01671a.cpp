#include <iostream>
#include <string>

void Yes(){
    std::cout << "YES" << std::endl;
}

void No() {
    std::cout << "NO" << std::endl;
}

void Solve() {

    char tmp = ' ';
    char prev = '#';
    int cur = 1;

    std::string s=" ";
    std::cin >> s;

    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            ++cur;
        }
        else {
            if (cur == 1) {
                No();
                return;
            }
            cur = 1;
        }
    }

    if (cur > 1) {
        Yes();
    }
    else {
        No();
    }

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        Solve();
    }

    return 0;

}