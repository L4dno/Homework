#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>

int main() {

    int n = 0;
    std::string code;

    std::cin >> n;
    code.reserve(n);
    std::cin >> code;
    std::reverse(code.begin(), code.end());

    std::list<char> decode;
    for (int i = 0; i < n; ++i) {
        decode.insert(std::next(decode.begin(), i / 2), code[i]);
    }

    for (auto symb : decode) {
        std::cout << symb;
    }

    return 0;

}