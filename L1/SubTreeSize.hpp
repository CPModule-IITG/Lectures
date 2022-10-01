//consider we have the graph g{adjacency list}
	vector<int> sz(n + 1, 1);

	function<void(int, int)> dfs = [&](int node, int par) {
		for (auto ch : g[node]) {
			if (ch ^ par) {
				dfs(ch, node);
				sz[node] += sz[ch];
			}
		}
	};

	dfs(1, 0);
