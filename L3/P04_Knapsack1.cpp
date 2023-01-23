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
	int n, w;
	cin >> n >> w;
	vector<int> ww(n), vv(n); //weight,value of each object

	for (int i = 0; i < n; i++) {
		cin >> ww[i] >> vv[i];
	}

	vector<int>dp(w + 1, 0ll);
	//dp[i][j] -> I have scanned the prefix of length i and max happiness achievable for taking a weight of j in the knapsack

	if (ww[0] <= w) {
		dp[ww[0]] = vv[0];
	}

	for (int i = 1; i < n; i++) {
		vector<int> nxt = dp;//dont take this
		for (int j = ww[i]; j <= w; j++) {
			if (j >= ww[i]) {
				nxt[j] = max(nxt[j], dp[j - ww[i]] + vv[i]);//take this item
			}
		}
		swap(dp, nxt);//rolling array technique
	}

	cout << *max_element(dp.begin(), dp.end()) << "\n";
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

