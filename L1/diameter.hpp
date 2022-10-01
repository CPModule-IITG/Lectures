  vector<int> dis(n + 1, -1); //stores the distance from the root

	int mx = -2, mxNode = 0;
	vector<int> p(n + 1, 0);
	function<void(int, int)> dfs = [&](int node, int par) {
		dis[node] = dis[par] + 1;
		p[node] = par;
		if (dis[node] > mx) {
			mx = dis[node];
			mxNode = node;
		}
		for (auto ch : g[node]) {
			if (ch ^ par) {
				dfs(ch, node);
			}
		}
	};

	dfs(1, 0);

	int x = mxNode;
	mx = -2;

	dfs(x, 0);

	int y = mxNode;
	int D = mx;

	// x-y is diamteric pair
	// to retrace the diamter use p array

	int cur = y;
	vector<int> path;
	while (1) {
		path.push_back(cur);
		if (cur == x) {
			break;
		}
		cur = p[cur];
	}
