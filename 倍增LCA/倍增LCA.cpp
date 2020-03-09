//λ���㷨��P3379
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
class edge {
public:
	int from, to, dist;
	edge(int a = 0, int b = 0, int c = 0) :from(a), to(b), dist(c) {}
};
vector<edge> edges;
vector<int> g[100001];
int n, s, dis[100001][20], fa[100001][20], depth[100001];
void dfs(int x) {
	for (int i = 1; i <= s; i++) {
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
		dis[x][i] = dis[x][i - 1] + dis[fa[x][i - 1]][i - 1];
	}
	for (int i = 0; i < g[x].size(); i++) {
		edge& e = edges[g[x][i]];
		depth[e.to] = depth[x] + 1;
		fa[e.to][0] = x;
		dis[e.to][0] = e.dist;
		dfs(e.to);
	}
}
int lca(int a, int b) {
	int ans = 0;
	if (depth[a] > depth[b]) a ^= b ^= a ^= b;
	for (int i = s; i >= 0; i--) {
		if (depth[a] < depth[b] && depth[fa[b][i]] >= depth[a]) {
			ans += dis[b][i];
			b = fa[b][i];
		}
	}
	for (int i = s; i >= 0; i--) {
		if (fa[a][i] != fa[b][i]) {
			ans += dis[a][i] + dis[b][i];
			a = fa[a][i]; b = fa[b][i];
		}
	}
	if (a != b) ans += dis[a][0] + dis[b][0];
	return ans;
}
int main() {
	cin >> n;
	s = floor(log(n + 0.0) / log(2.0));
	for (int i = 1; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edges.push_back(edge(x, y, z));
		g[x].push_back(edges.size() - 1);
	}
	depth[1] = 0;
	fa[1][0] = 0;
	dfs(1);
	int a, b;
	while (1) {
		cin >> a >> b;
		if (a == 0)break;
		cout << lca(a, b) << endl;
	}
	return 0;
}