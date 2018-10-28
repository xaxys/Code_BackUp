#include<bits/stdc++.h>
#define N 100010
using namespace std;
int head[N], to[N << 1], nxt[N << 1], v[N << 1], ecnt;
int n, m, ans = 0x7fffffff;
bool item[N];
struct node {
	int num = 0, dist = 0;
} p[N];
inline void addedge(int &x, int &y, int &z) {
	to[++ecnt] = y;
	v[ecnt] = z;
	nxt[ecnt] = head[x];
	head[x] = ecnt;
}
void dfs1(int x, int fa) {
	for (int i = head[x]; i; i = nxt[i]) {
		int &u = to[i];
		if (u == fa) continue;
		dfs1(u, x);
		if (p[u].num) {
			p[x].num += p[u].num;
			p[x].dist += p[u].dist + p[u].num * v[i];
		}
	}
	if (item[x]) p[x].num++;
}
void dfs2(int x, int fa, int va) {
	ans = min(ans, p[x].dist + va);
	for (int i = head[x]; i; i = nxt[i]) {
		int &u = to[i];
		if (u == fa) continue;
		int tmp = p[x].dist + (p[x].num - (p[u].num << 1) - item[x]) * v[i];
		tmp += ((m << 1) - p[x].num) * v[i] + va;
		dfs2(u, x, tmp);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y, z; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		addedge(x, y, z);
		addedge(y, x, z);
	}
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d%d", &x, &y);
		item[x] = item[y] = 1;
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	printf("%d\n", ans);
	return 0;
}