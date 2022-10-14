#include <iostream>
#include <array>

int main() {

	int t; std::cin >> t;
	int n, x, tmp;
	const int mxPlace = 400;
	std::array<int, mxPlace+1> places;

	while (t--) {
		std::cin >> n >> x;

		places.fill(0);
		for (int i = 0; i < n; ++i) {
			std::cin >> tmp;
			++places[tmp];
		}

		for (int i = 1; i <= mxPlace; ++i) {
			if (places[i] > 0)
				continue;
			else if (x > 0)
				--x;
			else {
				std::cout << i - 1 << std::endl;
				break;
			}
		}
	}

}