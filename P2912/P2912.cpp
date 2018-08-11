#include<bits/stdc++.h>//手写邻接表
#define maxn 1001
using namespace std;
struct edge {
	int to, dist, next;
};
int n, q, top[maxn], depth[maxn], num[maxn], fa[maxn], son[maxn];
int len[maxn];
int  g[maxn], ecnt;
edge e[maxn << 1];
void dfsinit(int x) {
	num[x] = 1;
	depth[x] = depth[fa[x]] + 1;
	for (int i = g[x]; i; i = e[i].next) {
		int& u = e[i].to;
		if (u == fa[x]) continue;
		len[u] = len[x] + e[i].dist;
		fa[u] = x;
		dfsinit(u);
		num[x] += num[u];
		if (!son[x] || num[son[x]] < num[u]) son[x] = u;
	}
}
void dfs(int x) {
	if (!top[x]) top[x] = x;
	top[son[x]] = top[x];
	for (int i = g[x]; i; i = e[i].next) {
		int& u = e[i].to;
		if (u == fa[x]) continue;
		dfs(u);
	}
}
int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (depth[top[x]] < depth[top[y]]) x ^= y ^= x ^= y;//swap(x,y)的位运算写法
		x = fa[top[x]];
	}
	if (depth[x] < depth[y]) x ^= y ^= x ^= y;
	return y;
}
void add(int x, int y, int z) {
	e[++ecnt].to = y;
	e[ecnt].dist = z;
	e[ecnt].next = g[x];
	g[x] = ecnt;
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	fa[1] = 1;
	dfsinit(1);
	dfs(1);
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", len[x] + len[y] - (len[lca(x, y)] << 1));
	}
	return 0;
}