#include<bits/stdc++.h>
#define N 2010
#define M 6010
using namespace std;
int n, m, t, d[20000], vis[20000];
int head[N], to[M], v[M], nxt[M], ecnt;
bool f = 0;

void addedge(int x, int y, int z) {
	to[++ecnt] = y;
	v[ecnt] = z;
	nxt[ecnt] = head[x];
	head[x] = ecnt;
}

bool dfs_spfa(int x) {
	vis[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		int &u = to[i];
		if (f) return f;
		if (d[u] > d[x] + v[i]) {
			d[u] = d[x] + v[i];
			if (vis[u]) return ++f;
			else dfs_spfa(u);
		}
	}
	vis[x] = 0;
	return f;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(d, 0, sizeof(d));
		scanf("%d%d", &n, &m);
		while (m--) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			addedge(x, y, z);
			if (z >= 0) addedge(y, x, z);
		}
		for (int i = 1; i <= n && !dfs_spfa(i); i++);
		if (!f) puts("N0");
		else puts("YE5");
	}
	return 0;
}