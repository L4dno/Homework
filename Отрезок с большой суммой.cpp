#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {

	int n; ll s;
	cin >> n >> s;

	vector<int> a(n);
	for (auto& i : a)
		cin >> i;

	int res = INT_MAX;

	int l = 0; ll x = 0;
	for (int r = 0; r < n; ++r) {

		x += a[r];

		/*while (x - a[l] >= s) {
			x -= a[l];
			++l;
		}

		if (x>=s)
			res = min(res, r - l + 1);*/

		//ещё один способ
		//при котором поддерживаем плохой отрезок
		//а отрезок от l-1 хороший
		//только надо проверять, что пустой отрезок плохой
		//чтобы l не уехал дальше r

		while (x >= s) {
			x -= a[l];
			++l;
		}

		if (l > 0)
			res = min(res, r - l + 2);

	}

	if (res == INT_MAX)
		cout << -1;

	else
		cout << res;

	return 0;

}