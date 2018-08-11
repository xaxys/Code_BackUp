#include<bits/stdc++.h>
using namespace std;
int n, m, ans = 0x7f7f7f7f, pop[110], depth[110], pre[110], dis[110];
vector<int> g[110];
void dfs(int root, int fa) {
	depth[root] = depth[fa] + 1;
	for (int i = 0; i < g[root].size(); i++) {
		int& u = g[root][i];
		if (u == fa) continue;
		dfs(u, root);
		pre[root] += pre[u];
	}
}
void dp(int root, int fa) {
	for (int i = 0; i < g[root].size(); i++) {
		int& u = g[root][i];
		if (u == fa) continue;
		dis[u] = dis[root] + pre[1] - pre[u] - pre[u];
		ans = min(ans, dis[u]);
		dp(u, root);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> pop[i] >> x >> y;
		pre[i] = pop[i];
		if (x) {
			g[i].push_back(x);
			g[x].push_back(i);
		}
		if (y) {
			g[i].push_back(y);
			g[y].push_back(i);
		}
	}
	depth[0] = 0;
	depth[1] = 0;
	dfs(1,0);
	for (int i = 1; i <= n; i++) dis[1] += (depth[i] - 1) * pop[i];
	ans = dis[1];
	dp(1, 0);
	cout << ans << endl;
	return 0;
}
