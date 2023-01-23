#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int MOD = 1e9 + 7;
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));

	for (auto &x : a) {
		for (auto &y : x) {
			cin >> y;
		}
	}

	vector<vector<int>> dp(n, vector<int>(m, 0ll));
	//dp[i][j] -> number of ways to reach the index i,j

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#' || i + j == 0) {
				continue;
			}

			dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n - 1][m - 1] << "\n";
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

