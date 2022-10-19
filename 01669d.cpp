#include <iostream>
#include <string>

void yes() {
	std::cout << "YES" << "\n";
}

void no() {
	std::cout << "NO" << "\n";
}

void Solve() {

	int n = 0;
	std::string text = "";
	std::cin >> n >> text;
	text.push_back('W');

	int r_cnt = 0;
	int b_cnt = 0;
	for (auto c : text) {
		if (c == 'R') {
			++r_cnt;
		}
		else if (c == 'B') {
			++b_cnt;
		}
		else {
			if ((b_cnt == 0) ^ (r_cnt == 0)) {
				no();
				return;
			}
			r_cnt = 0;
			b_cnt = 0;
		}
	}

	yes();

}

int main() {

	int t = 0;
	std::cin >> t;

	while (t-- > 0) {
		Solve();
	}

	system("pause");

	return 0;

}