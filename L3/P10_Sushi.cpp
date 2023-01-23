#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int MAXN = 305;
void solve() {
	int n;
	cin >> n;
	vector<int> cnt(4, 0ll);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		cnt[x]++;
	}
	vector<vector<vector<long double>>> dp(MAXN, vector<vector<long double>>(MAXN, vector<long double>(MAXN, 0.0)));
	vector<vector<vector<bool>>> vis(MAXN, vector<vector<bool>>(MAXN, vector<bool>(MAXN, false)));
	function<long double(int, int, int)> dfs = [&](int x, int y, int z) {
		//x-> count of 1, y -> count of 2, z -> count of 3
		// dp[x][y][z] ->

		if (x == 0 && y == 0 && z == 0) {
			return (long double)0.0;
		}
		if (vis[x][y][z]) {
			return dp[x][y][z];
		}
		long double &ans = dp[x][y][z];
		int sm = x + y + z;
		ans = (1.*n) / sm;
		if (x) {
			ans += (dfs(x - 1, y, z)) * ((1.0 * x) / (1.0 * sm));
		}

		if (y) {
			ans += (dfs(x + 1, y - 1, z)) * ((1.0 * y) / (1.0 * sm));
		}

		if (z) {
			ans += (dfs(x, y + 1, z - 1)) * ((1.0 * z) / (1.0 * sm));
		}
		vis[x][y][z] = 1;
		return ans;
	};

	cout << fixed << setprecision(12) << dfs(cnt[1], cnt[2], cnt[3]) << "\n";
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

