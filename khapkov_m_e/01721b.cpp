#include <iostream>

int main() {

    //FILE* stream;
    //freopen_s(&stream, "input.txt", "r", stdin);
    //freopen_s(&stream, "output.txt", "w", stdout);

    int t; std::cin >> t;
    int n, m, lx, ly, dist;

    while (t--) {
        std::cin >> n >> m >> lx >> ly >> dist;
        /*if ((lx - dist <= 1 && ly - dist <= 1) ||
            (lx + dist >= n && ly + dist >= m) ||
            (abs(n-lx)+abs(m-ly)<=dist) ||
            (lx+dist>=n && lx-dist<=1)||
            (ly+dist>=m && ly-dist<=1))*/
        //ïî÷ -1 ¸ïòà??!??!?
        if (std::min(lx-1,m-ly)<=dist && std::min(ly-1,n-lx)<=dist)
            std::cout << -1 << "\n";
        else
            std::cout << n + m - 2<< std::endl;
    }

    return 0;

}