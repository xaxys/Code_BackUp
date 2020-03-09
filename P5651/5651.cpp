#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct edge{
	int f, t, v, nxt;
} edges[N << 1];
int cnt;
int head[N];
void addedge(int x, int y, int z) {
	edges[++cnt].f = x;
	edges[cnt].t = y;
	edges[cnt].v = z;
	edges[cnt].nxt = head[x];
	head[x] = cnt;
}

int f[N];
int find(int x) {
	return x == f[x] ? x : find(f[x]);
}

int n, m, q;
int val[N], fa[N];
void dfs(int x) {
	for (int i = head[x]; i; i = edges[i].nxt) {
		int& u = edges[i].t;
		if (u == fa[x]) continue;
		fa[u] = x;
		val[u] = val[x] ^ edges[i].v;
		dfs(u);
	}
}


int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) f[i] = i;
	int k = 0;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		int fx = find(x), fy = find(y);
		if (fx != fy) {
			f[fx] = fy;
			k++;
			addedge(x, y, z);
			addedge(y, x, z);
		}
	}
	assert(k == n - 1);
	dfs(1);
	for (int i = 1; i <= q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", val[x] ^ val[y]);
	}
	return 0;
} 