#include <iostream>
#include <vector>

int main() {

	const int MAX_N = 2e5;

	int t; std::cin >> t;

	int n, cur = 0, cnt = 0;
	std::vector<int> input(MAX_N);
	while (t--) {

		std::cin >> n;

		for (int i = 0; i < n; ++i)
			std::cin >> input[i];

		cur = input[n - 1];
		for (int j = n - 1; j >= 0; --j)
			if (input[j] > cur) {
				cur = input[j];
				++cnt;
			}

		std::cout << cnt << "\n";
		cnt = 0;

	}

	return 0;

}