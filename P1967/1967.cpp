#include <bits/stdc++.h>
#define N 10010
using namespace std;
struct node {
	int f, t, v;
} edg[51000], add[10010];
int n, m, q, cnt, idx;
int to[N << 1], head[N], nxt[N << 1], z[N << 1];
int p[N];
int depth[N], fa[N], faz[N], top[N], maxz[N], son[N], siz[N];

inline bool cmp(const node &a, const node &b) { return a.v>b.v; }
inline int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
inline void add_edge(int a, int b, int c) {
	to[++cnt] = b;
	nxt[cnt] = head[a];
	head[a] = cnt;
	z[cnt] = c;

	to[++cnt] = a;
	nxt[cnt] = head[b];
	head[b] = cnt;
	z[cnt] = c;
}
inline void dfsinit(int x) {
	siz[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		int &u = to[i];
		if (u == fa[x]) continue;
		depth[u] = depth[x] + 1;
		fa[u] = x;
		faz[u] = z[i];
		dfsinit(u);
		siz[x] += siz[u];
		if (!son[x] || siz[u] > siz[son[x]]) son[x] = u;
	}
}
inline void dfs(int x) {
	if (!top[x]) {
		top[x] = x;
		maxz[x] = 0x7f7f7f7f;
	}
	top[son[x]] = top[x];
	for (int i = head[x]; i; i = nxt[i]) {
		int &u = to[i];
		if (u == fa[x]) continue;
		if (u == son[x]) maxz[u] = min(maxz[x], z[i]);
		dfs(u);
	}
}
inline int check(int a, int b) {
	int minz = 0x7f7f7f7f;
	while (top[a] != top[b]) {
		if (depth[top[a]] < depth[top[b]]) a ^= b ^= a ^= b;
		minz = min(minz, min(maxz[a], faz[top[a]]));
		a = fa[top[a]];
	}
	if (depth[a] < depth[b]) a ^= b ^= a ^= b;
	while (a != b) {
		minz = min(minz, faz[a]);
		a = fa[a];
	}
	return minz;
}
inline void kruskal() {
	sort(edg + 1, edg + m + 1, cmp);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++) {
		int dx = find(edg[i].f), dy = find(edg[i].t);
		if (dx != dy) p[dx] = dy, add[++idx] = edg[i];
	}
	for (int i = 1; i <= idx; i++) add_edge(add[i].f, add[i].t, add[i].v);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edg[i].f = x, edg[i].t = y, edg[i].v = z;
	}
	kruskal();
	//set<int> rec;
	//for (int i = 1; i <= n; i++) {
	//	int x = find(i);
	//	if (!rec.count(x)) {
	//		rec.insert(x);
	//		s.push_back(i);
	//	}
	//}
	//for (int i = 0; i < s.size(); i++) {
	//	dfsinit(s[i]);
	//	dfs(s[i]);
	//}
	dfsinit(1);
	dfs(1);
	scanf("%d", &q);
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int dx = find(a), dy = find(b);
		if (dx != dy) {
			printf("-1\n");
			continue;
		}
		printf("%d\n", check(a, b));
	}
}