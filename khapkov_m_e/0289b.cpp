#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long Count(const std::vector<std::vector<int>>& m, int x) {

	long long cnt = 0;

	for (int i = 0; i < m.size(); ++i)
		for (int j = 0; j < m[0].size(); ++j)
			cnt += std::abs(x - m[i][j]);

	return cnt;

}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, d; 
	std::cin >> n >> m >> d;

	std::vector<std::vector<int>> mat(n, std::vector<int>(m, 0));
	bool first = true;
	bool isReal = true;

	std::cin >> mat[0][0];
	int rem = mat[0][0] % d;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) {

			if (!first) {

				std::cin >> mat[i][j];

				if (mat[i][j] % d != rem) {
					isReal = false;
					break;
				}

			}
			
			first = false;
			mat[i][j] /= d;

		}


	if (!isReal)
		std::cout << -1;

	else {

		int l = 0, r = 1e4;

		while (r - l > 2) {

			int m1 = l + (r - l) / 3,
				m2 = m1 + (r - l) / 3;

			if (Count(mat, m1) < Count(mat, m2))
				r = m2;

			else
				l = m1;

		}

		std::cout << std::min(Count(mat, l), Count(mat,l+1));

	}

	return 0;

}