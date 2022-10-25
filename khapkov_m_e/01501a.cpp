#include <iostream>
#include <vector>

struct Train {
    int arr_time = 0;
    int dep_time = 0;
};

void Solve() {

    int n = 0;
    std::cin >> n;

    std::vector<Train> a(n+1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i].arr_time >> a[i].dep_time;
    }
   
    int cur_time = 0;
    int delay = 0;
    int waiting = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> delay;
        //доехали до станции
        cur_time += a[i].arr_time - a[i - 1].dep_time + delay;

        if (i == n)
            break;

        //ждём отбытия или необходимый перерыв
        waiting = (a[i].dep_time - a[i].arr_time + 1) / 2;
        if (a[i].dep_time >= waiting + cur_time) {
            cur_time = a[i].dep_time;
        }
        else {
            cur_time += waiting;
        }
    }

    std::cout << cur_time << std::endl;

}

int main() {

    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        Solve();
    }

    return 0;

}