#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int INF = 2e9;
void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	vector<int> dp(n, INF);
	//dp[i] -> min cost to reach the ith stone
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int prev = 1; prev <= k; prev++) {
			if (i - prev < 0) {
				break;
			}
			dp[i] = min(dp[i], dp[i - prev] + abs(a[i] - a[i - prev]));
		}
	}

	cout << dp[n - 1] << "\n";
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

