#include <iostream>
#include <vector>
#include <algorithm>

int main() {

	int n; std::cin >> n;
	std::vector<int> a(n);

	for (auto& i : a)
		std::cin >> i;

	std::vector<int> res;
	for (int i = 0; i < n; ++i)
		if (std::find(a.begin() + i + 1, a.end(), a[i]) == a.end()) {
			res.push_back(a[i]);
		}

	std::cout << res.size() << std::endl;
	for (auto i : res)
		std::cout << i << " ";

	return 0;

}