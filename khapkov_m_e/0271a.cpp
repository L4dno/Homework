#include <iostream>

using namespace std;

int main() {

    int y; cin >> y;

    //for (y+=1;y<=9999;++y)
    for (int i = y + 1; i <= 9999; ++i) {
        y = i;
        int a = y % 10; y /= 10;
        int b = y % 10; y /= 10;
        int c = y % 10; y /= 10;
        int d = y % 10; y /= 10;

        if (a != b && a != c && a != d && b != c && b != d && c != d) {
            cout << i;
            break;
        }

    }

    return 0;
}