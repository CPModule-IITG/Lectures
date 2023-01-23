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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	vector<int> dp(k + 1, -1ll);
	//dp[i] -> is it possible to win for the first player if we start with i stones

	function<int(int)> dfs = [&](int x) {
		if (dp[x] != -1) {
			return dp[x];
		}
		dp[x] = 0;
		for (int i = 0; i < n; i++) {
			if (x >= a[i]) {
				dp[x] = dp[x] | (!dfs(x - a[i]));
			}
		}
		return dp[x];
	};

	cout << (dfs(k) ? "First\n" : "Second\n");
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

