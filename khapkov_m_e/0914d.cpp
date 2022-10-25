#include <iostream>
#include <vector>

int GCD(int x, int y) {
	while (x && y) {
		if (x > y) x %= y;
		else y %= x;
	}
	return x + y;
}

struct segtree {

	std::vector<int> tree;
	int size = 1;
	int cnt = 0;

	void init(const std::vector<int>& a) {
		while (size < a.size())
			size *= 2;
		tree.resize(size * 2 - 1);
		build(a, 0, 0, size);
	}

	void build(const std::vector<int>& a, int x, int lx, int rx) {

		if (rx - lx == 1) {
			if (lx < a.size())
				tree[x] = a[lx];
			return;
		}

		int m = (lx + rx) / 2;

		build(a, x * 2 + 1, lx, m);
		build(a, x * 2 + 2, m, rx);

		tree[x] = GCD(tree[x * 2 + 1], tree[x * 2 + 2]);

	}

	void update(int i, int v, int x, int lx, int rx) {

		if (rx - lx == 1) {
			tree[x] = v;
			return;
		}

		int m = (lx + rx) / 2;

		if (i < m)
			update(i, v, x * 2 + 1, lx, m);

		else
			update(i, v, x * 2 + 2, m, rx);

		tree[x] = GCD(tree[x * 2 + 1], tree[x * 2 + 2]);

	}

	void update(int i, int v) {
		update(i, v, 0, 0, size);
	}

	void query(int l, int r, int v, int x, int lx, int rx) {

		bool notDivide = tree[x] % v;

		if ((l >= rx || lx >= r) || (!notDivide) || (cnt > 1))
			return;

		if ((rx - lx == 1) && notDivide) {
			cnt++;
			return;
		}

		int m = (lx + rx) / 2;

		query(l, r, v, x * 2 + 1, lx, m);
		query(l, r, v, x * 2 + 2, m, rx);

	}

	bool query(int l, int r, int v) {
		query(l, r, v, 0, 0, size);
		bool res = cnt <= 1;
		cnt = 0;
		return  res;
	}

};

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n; std::cin >> n;
	std::vector<int> a(n);

	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	segtree st; st.init(a);

	int m; std::cin >> m;

	for (int i = 0; i < m; ++i) {

		int op; std::cin >> op;

		if (op == 1) {
			int l, r, x; std::cin >> l >> r >> x;
			l -= 1;
			if (st.query(l, r, x)) std::cout << "YES" << "\n";
			else std::cout << "NO" << "\n";
		}

		else {
			int i, v; std::cin >> i >> v;
			i -= 1;
			st.update(i, v);
		}

	}

	return 0;

}