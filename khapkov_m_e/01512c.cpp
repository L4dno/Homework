#include <iostream>
#include <string>

char rvrs(char c) {
    if (c == '?')
        return '?';
    if (c == '0')
        return '1';
    return '0';
}

int cnt(const std::string& s, char smpl) {
    int res = 0;
    for (auto i : s)
        if (i == smpl)
            ++res;
    return res;
}

int main() {

    int t; std::cin >> t;

    int a;//zeros
    int b;//ones
    std::string s;
    s.reserve(2e5);
    int n = 0;
    bool bad = false;

    while (t--) {

        a = 0;
        b = 0;
        s.clear();
        n = 0;
        bad = false;

        //считали ввод
        std::cin >> a >> b >> s;
        n = a + b;

        //заменили все одиночные вопросы
        //если встретили противоречащие символы,
        //то вывели -1 и bad = истина
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == '?')
                s[i] = s[n - i - 1];
            else {
                if (s[i] != rvrs(s[n - i - 1]))
                    s[n - i - 1] = s[i];
                else {
                    std::cout << -1 << "\n";
                    bad = true;
                    break;
                }
            }
        }

        //если встретили противоречие, то больше делать нечего
        if (bad)
            continue;

        //заменили центральный символ
        if (n & 1 && s[n/2]==rvrs(s[n/2])) {
            if (a & 1)
                s[n/2] = '0';
            else
                s[n/2] = '1';
        }

        //нашли сколько надо ещё поставить
        a -= cnt(s, '0');
        b -= cnt(s, '1');

        
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == '?') {
                if (a > 0) {
                    s[i] = '0';
                    s[n - i - 1] = '0';
                    a -= 2;
                }
                else {
                    s[i] = '1';
                    s[n - i - 1] = '1';
                    b -= 2;
                }
            }
        }

        //если обязательных символов больше необходимых
        //то все плохо
        if (a < 0 || b < 0) {
            std::cout << -1 << "\n";
            continue;
        }

        //иначе все можно расставить
        std::cout << s<<std::endl;


    }

    return 0;

}