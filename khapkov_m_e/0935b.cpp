#include <iostream>
#include <string>

int main() {

    int n = 0;
    std::cin >> n;
    std::string s = "";
    std::cin >> s;

    int posx = 0;
    int posy = 0;
    bool which = false;//1 - false, up; 2 - true, down
    bool first = true;
    int res = 0;

    for (char mv : s) {

        if (mv == 'U')
            posx += 1;
        else
            posy += 1;

        //we are in 1st
        if (posy > posx) {
            if (which && !first)
                res += 1;
            which = false;
        }
        //we are in sec
        else if (posy<posx){
            if (!which && !first)
                res += 1;
            which = true;
        }


        first = false;

    }

    std::cout << res;

    return 0;

}