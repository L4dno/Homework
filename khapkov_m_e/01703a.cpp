#include <iostream>
#include <string>
#include <cctype>

void Yes() {
    std::cout << "YES" << std::endl;
}

void No() {
    std::cout << "NO" << std::endl;
}

void Solve() {

    std::string tmp = "";
    std::cin >> tmp;

    for (char& c : tmp) {
        c = std::tolower(c);
    }

    if ("yes" == tmp) {
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

}