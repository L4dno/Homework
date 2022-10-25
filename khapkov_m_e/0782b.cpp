#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

struct man {
	long double x, v;
};

struct seg {
	long double l, r;
};

seg intersect(seg f, seg s) {
	return { std::max(f.l, s.l), std::min(f.r,s.r) };
}

bool good(const std::vector<man>& a, long double t) {

	seg line = { -1e9, 1e9 };

	for (const auto& item : a) {
		seg tmp = { item.x - item.v * t, item.x + item.v * t };
		line = intersect(line, tmp);
	}

	return line.l < line.r;
}

int main() {

	int n; std::cin >> n;

	std::vector<man> a(n);

	for (int i = 0; i < n; ++i)
		std::cin >> a[i].x;

	for (int i = 0; i < n; ++i)
		std::cin >> a[i].v;

	long double l = 0;
	long double r = 1e10;
	long double m;

	for (int i = 0; i < 100; ++i) {

		m = (l + r) / 2;

		if (good(a, m))
			r = m;
		else
			l = m;

	}

	std::cout << std::fixed << std::setprecision(6) << r;

	return 0;

}