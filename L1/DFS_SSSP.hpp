//consider we have the graph g{adjacency list}
	
vector<int> dis(n + 1, -1); //stores the distance from the root
	
function<void(int, int)> dfs = [&](int node, int par) { // lamda function in CPP
    dis[node] = dis[par] + 1;
		for (auto ch : g[node]) {
			if (ch ^ par) {
				dfs(ch, node);
			}
		}
};

dfs(1, 0);
