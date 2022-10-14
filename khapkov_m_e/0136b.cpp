#include <iostream>
#include <vector>
#include <algorithm>

int FindTor(int a, int c) {
	std::vector<int> repr;

	int da, dc;
	while (a || c) {
		da = a % 3;
		dc = c % 3;

		repr.push_back((dc - da + 3) % 3);

		a /= 3;
		c /= 3;
	}
	reverse(repr.begin(), repr.end());
	int ans = repr[0];

	for (int i = 1; i < repr.size(); ++i) {
		ans = ans * 3 + repr[i];
	}

	return ans;
}

int main() {

	int a, c;
	std::cin >> a >> c;

	if (a || c)
		std::cout << FindTor(a, c);
	else
		std::cout << 0;
	system("pause");

	return 0;

}