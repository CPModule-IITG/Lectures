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
	vector<long double> p(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> p[i + 1]; // probablity of heads
	}

	vector<vector<long double>> dp(n + 1, vector<long double>(n + 1, 0.0));
	//dp[i][j] -> we have tossed first i coins out of which j are heads

	dp[1][1] = p[1];
	dp[1][0] = 1 - p[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = dp[i - 1][j] * (1 - p[i]) + (j > 0 ? dp[i - 1][j - 1] * p[i] : 0.0);
		}
	}
	long double ans = 0;
	for (int j = 0; j <= n; j++) {
		if (j > n - j) {
			ans += dp[n][j];
		}
	}

	cout << fixed << setprecision(12) << ans << "\n";
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


