#include <vector>
#include <iostream>

int main() {

	int t; std::cin >> t;
	int n, k, r, c, d, im, jm;

	while (t--) {
		std::cin >> n >> k >> r >> c;
		r %= k;
		c %= k;
		d = r - c;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {

				im = i % k; jm = j % k;

				if ((im - d + k) % k == jm)
					std::cout << 'X';
				else
					std::cout << '.';
			}
			std::cout << std::endl;
		}
	}

	return 0;
}