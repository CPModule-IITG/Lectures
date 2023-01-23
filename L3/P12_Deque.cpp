#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
	//dp[i][j][k] -> max score taro can make will playing on the subarray [i..j], where kth player takes the turn

	function<int(int, int, int)> dfs = [&](int i, int j, int k) {
		if (i > j) {
			return 0ll;
		}
		int &ans = dp[i][j][k];
		if (ans != -1) {
			return ans;
		}
		if (k == 0) {
			ans = max(dfs(i + 1, j, 1) + a[i], dfs(i, j - 1, 1) + a[j]);
		} else {
			ans = min(dfs(i + 1, j, 0), dfs(i, j - 1, 0));
		}
		return ans;
	};
	cout << 2 * dfs(0, n - 1, 0) - accumulate(a.begin(), a.end(), 0ll) << "\n";
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

