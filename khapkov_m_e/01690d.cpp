#include <iostream>
#include <algorithm>
#include <string>

void Solve() {

	int n = 0;
	int k = 0;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s;

	int r = 0;
	int cnt = 0;
	for (;r < k;++r) {
		if (s[r] == 'B') {
			++cnt;
		}
	}

	int mx_black = -2e9;
	for (;r < n;++r) {
		mx_black = std::max(mx_black, cnt);
		if (s[r] == 'B') {
			++cnt;
		}
		if (s[r - k] == 'B') {
			--cnt;
		}
	}
	mx_black = std::max(mx_black, cnt);

	std::cout << k - mx_black << std::endl;

}

int main() {

	int t = 0;
	std::cin >> t;

	while (t-- > 0) {
		Solve();
	}

	//system("pause");

	return 0;

}
