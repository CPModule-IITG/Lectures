#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

const int INF = 1e18;
void solve() {
	int n, w;
	cin >> n >> w;
	vector<int> ww(n), vv(n); //weight,value of each object
	for (int i = 0; i < n; i++) {
		cin >> ww[i] >> vv[i];
	}

	vector<int> dp(accumulate(vv.begin(), vv.end(), 5ll), INF);

	//dp[i][j] -> I have scanned the prefix of length of i and taken the max happiness of j, then the min weigth to do so?
	dp[vv[0]] = ww[0];
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		vector<int> nxt = dp;//dont take
		for (int j = vv[i]; j < dp.size(); j++) {
			nxt[j] = min(nxt[j], dp[j - vv[i]] + ww[i]);//take
		}
		swap(nxt, dp); //rolling array technique
	}

	for (int i = dp.size() - 1; i >= 0; i--) {
		if (dp[i] <= w) {
			cout << i << "\n";
			return;
		}
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

