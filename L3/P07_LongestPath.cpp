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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> in(n + 1, 0ll);
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		in[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			q.push(i);
		}
	}
	vector<int> tp;//topSort
	while (q.size()) {
		auto node = q.front(); q.pop();

		tp.push_back(node);
		for (auto ch : g[node]) {
			in[ch]--;
			if (!in[ch]) {
				q.push(ch);
			}
		}
	}
	vector<int> dp(n + 1, 0ll); //dp[i] -> max length path from node i
	for (int i = tp.size() - 1; i >= 0; i--) {
		for (auto ch : g[tp[i]]) {
			dp[tp[i]] = max(dp[tp[i]], dp[ch] + 1);
		}
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

