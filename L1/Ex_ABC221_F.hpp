#include <bits/stdc++.h>
using namespace std;
/*
https://atcoder.jp/contests/abc221/tasks/abc221_f
*/
#define int long long

const int MOD = 998244353;

int add(int a, int b, int c = MOD) {int res = a + b; return (res >= c ? res % c : res);}
int sub(int a, int b, int c = MOD) {int res; if (abs(a - b) < c)res = a - b; else res = (a - b) % c; return (res < 0 ? res + c : res);}
int mul(int a, int b, int c = MOD) {int res = (int)a * b; return (res >= c ? res % c : res);}

template<typename T>T binpow(T e, T n) {T x = 1, p = e; while (n) {if (n & 1)x = x * p; p = p * p; n >>= 1;} return x;}
template<typename T>T binpow2(T e, T n, T m = MOD) {T x = 1, p = e; while (n) {if (n & 1)x = mul(x, p, m); p = mul(p, p, m); n >>= 1;} return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y) {
	T xx = 0, yy = 1; y = 0; x = 1; while (b) {
		T q = a / b, t = b; b = a % b; a = t; \
		t = xx; xx = x - q * xx; x = t; t = yy; yy = y - q * yy; y = t;
	} return a;
}
template<typename T>T mod_inverse(T a, T n = MOD) {T x, y, z = 0; T d = extended_euclid(a, n, x, y); return (d > 1 ? -1 : sub(x, z, n));}

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> v(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int mx_node = 0, mx_dis = -1;
	vector<int> par(n + 1);
	function<void (int, int, int)> dfs = [&](int node, int p, int d) {
		par[node] = p;
		if (mx_dis < d) {
			mx_dis = d;
			mx_node = node;
		}
		for (auto child : v[node]) {
			if (child ^ p) {
				dfs(child, node, d + 1);
			}
		}
	};

	dfs(0, -1, 0);
	int e1 = mx_node;
	// one of the ends of diameter
	mx_dis = -1;
	dfs(e1, -1, 0);
	int e2 = mx_node;
	int dia = mx_dis;

	int cur = e2;
	vector<int> path;//stores the dia
	while (cur != -1) {
		path.push_back(cur); cur = par[cur];
	}

	int cnt = 0;
	function<void (int, int, int, int)> dfs_cnt = [&](int node, int par, int d, int check) {
		if (d == check) {
			cnt++;
		}
		for (auto child : v[node]) {
			if (child ^ par) {
				dfs_cnt(child, node, d + 1, check);
			}
		}
	};
	if (dia % 2 == 0) {
		int center = path[(path.size() + 1) / 2 - 1];

		vector<int> pos;

		for (auto child : v[center]) {
			cnt = 0;
			dfs_cnt(child, center, 0ll, dia / 2 - 1);
			pos.push_back(cnt);
		}
		int ans = 1, sm = 0;

		for (auto x : pos) {
			ans = mul(ans, x + 1);
			sm = add(sm, x);
		}
		sm = add(sm, 1ll); // not choosing anything

		cout << sub(ans, sm) << "\n";
	} else {

		int center1 = path[path.size() / 2 - 1];
		int center2 = path[path.size() / 2];

		cnt = 0;
		dfs_cnt(center1, center2, 0, dia / 2);
		int cnt1 = cnt;

		cnt = 0;
		dfs_cnt(center2, center1, 0, dia / 2);
		int cnt2 = cnt; //taking center2

		cout << mul(cnt1, cnt2) << "\n";
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	//cin >> t;

	while (t--) {
		solve();
	}

	// cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}

