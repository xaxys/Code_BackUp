#include<bits/stdc++.h>
using namespace std;
int n, k, val[110], dp[110][110], ans = 0;
vector<int> g[110];
void dfs(int u, int fa) {
	dp[u][1] = val[u];
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa) continue;
		dfs(v, u);
		for (int j = k; j >= 1; j--)
			for (int l = 1; j + l <= k; l++)
				dp[u][j + l] = max(dp[u][j + l], dp[v][l] + dp[u][j]);
	}
}
int main() {
	while (scanf("%d%d", &n, &k) == 2) {
		ans = 0;
		memset(dp, -0x3f, sizeof(dp));
		for (int i = 0; i < n; i++) scanf("%d", &val[i]);
		for (int i = 1; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(0, -1);
		for (int i = 0; i < n; i++) ans = max(ans, dp[i][k]);
		printf("%d\n", ans);
	}
	return 0;
}
