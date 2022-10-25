#include <iostream>

int Solve() {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    std::cin >> a >> b >> c >> d;

    if (!(a || b || c || d))
        return 0;
    else if (a && b && c && d)
        return 2;
    return 1;

}

int main() {
    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        std::cout<<Solve()<<"\n";
    }
}