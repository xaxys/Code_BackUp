/*#include<bits/stdc++.h>//vector邻接表
#define maxn 500005
using namespace std;
int n, m, s, top[maxn], depth[maxn], siz[maxn], fa[maxn], son[maxn];
//int len[maxn];
vector<int> g[maxn];
void dfsinit(int x) {
	siz[x] = 1;
	depth[x] = depth[fa[x]] + 1;
	for (int i = 0; i < g[x].size(); i++) {
		int& u = g[x][i];

		if (u == fa[x]) continue;
		//len[u] = len[x] + dist(x,u);
		fa[u] = x;
		dfsinit(u);
		siz[x] += siz[u];
		if (!son[x] || siz[son[x]] < siz[u]) son[x] = u;
	}
}
void dfs(int x) {
	if (!top[x]) top[x] = x;
	top[son[x]] = top[x];
	for (int i = 0; i < g[x].size(); i++) {
		int& u = g[x][i];
		if (u == fa[x]) continue;
		dfs(u);
	}
}
int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (depth[top[x]] < depth[top[y]]) x ^= y ^= x ^= y;
		x = fa[top[x]];
	}
	if (depth[x] < depth[y]) x ^= y ^= x ^= y;
	return y;
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	fa[s] = s;
	dfsinit(s);
	dfs(s);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x,y));
	}
	return 0;
}*/




/*#include<bits/stdc++.h>//手写邻接表
//#define AI __inline__ __attribute__((always_inline))
#define AI __forceinline
#define maxn 500005
using namespace std;
struct edge {
	int to, next;
};
int n, m, s, top[maxn], depth[maxn], siz[maxn], fa[maxn], son[maxn];
//int len[maxn];
int  g[maxn], ecnt;
edge e[maxn << 1];
AI void dfsinit(int x) {
	siz[x] = 1;
	depth[x] = depth[fa[x]] + 1;
	for (int i = g[x]; i; i = e[i].next) {
		int& u = e[i].to;
		if (u == fa[x]) continue;
		//len[u] = len[x] + dist(x,u);
		fa[u] = x;
		dfsinit(u);
		siz[x] += siz[u];
		if (!son[x] || siz[son[x]] < siz[u]) son[x] = u;
	}
}
AI void dfs(int x) {
	if (!top[x]) top[x] = x;
	top[son[x]] = top[x];
	for (int i = g[x]; i; i = e[i].next) {
		int& u = e[i].to;
		if (u == fa[x]) continue;
		dfs(u);
	}
}
AI int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (depth[top[x]] < depth[top[y]]) x ^= y ^= x ^= y;//swap(x,y)的位运算写法
		x = fa[top[x]];
	}
	if (depth[x] < depth[y]) x ^= y ^= x ^= y;
	return y;
}
AI void add(int x, int y) {
	e[++ecnt].to = y;
	e[ecnt].next = g[x];
	g[x] = ecnt;
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	fa[s] = s;
	dfsinit(s);
	dfs(s);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y));
	}
	return 0;
}*/


/*#include<bits/stdc++.h>//手写邻接表[前向星]
#define AI inline
#define maxn 500005
using namespace std;
int n, m, s;
int top[maxn], depth[maxn], siz[maxn], fa[maxn], son[maxn];
//int len[maxn];
int  to[maxn << 1], nxt[maxn << 1], g[maxn], ecnt;
AI void dfsinit(int x) {
	siz[x] = 1;
	depth[x] = depth[fa[x]] + 1;
	for (int i = g[x]; i; i = nxt[i]) {
		int& u = to[i];
		if (u == fa[x]) continue;
		//len[u] = len[x] + dist(x,u);
		fa[u] = x;
		dfsinit(u);
		siz[x] += siz[u];
		if (!son[x] || siz[son[x]] < siz[u]) son[x] = u;
	}
}
AI void dfs(int x) {
	if (!top[x]) top[x] = x;
	top[son[x]] = top[x];
	for (int i = g[x]; i; i = nxt[i]) {
		int& u = to[i];
		if (u == fa[x]) continue;
		dfs(u);
	}
}
AI int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (depth[top[x]] < depth[top[y]]) x ^= y ^= x ^= y;//swap(x,y)的位运算写法
		x = fa[top[x]];
	}
	if (depth[x] < depth[y]) x ^= y ^= x ^= y;
	return y;
}
AI void add(int x, int y) {
	to[++ecnt] = y;
	nxt[ecnt] = g[x];
	g[x] = ecnt;
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	fa[s] = s;
	dfsinit(s);
	dfs(s);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y));
	}
	return 0;
}*/

#include<bits/stdc++.h>//手写邻接表[前向星] + [BFS初始化]
#define AI inline
#define maxn 500005
using namespace std;
int n, m, s;
int top[maxn], depth[maxn], siz[maxn], fa[maxn], son[maxn];
//int len[maxn];
int  to[maxn << 1], nxt[maxn << 1], g[maxn], ecnt;
AI void bfsinit(int s) {
	int *q = new int[maxn], h = 0, t = 1;
	siz[s] = 1;
	q[1] = s;
	while (h < t) {
		h++;
		int& x = q[h];
		for (int i = g[x]; i; i = nxt[i]) {
			int& u = to[i];
			if (u == fa[x]) continue;
			//len[u] = len[x] + dist(x,u);
			depth[u] = depth[x] + 1;
			fa[u] = x;
			siz[u] = 1;
			q[++t] = u;
		}
	}
	for (int i = t; i >= 2; i--) {
		int& u = q[i], x = fa[u];
		siz[x] += siz[u];
		if (!son[x] || siz[son[x]] < siz[u]) son[x] = u;
	}
	for (int i = 1; i <= t; i++) {
		int& u = q[i];
		if (!top[u]) {
			top[u] = u;
			int v = u;
			for (int v = u; v; v = son[v]) {
				top[v] = u;
			}
		}
	}
	delete[] q;
}
AI int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (depth[top[x]] < depth[top[y]]) x ^= y ^= x ^= y;//swap(x,y)的位运算写法
		x = fa[top[x]];
	}
	if (depth[x] < depth[y]) x ^= y ^= x ^= y;
	return y;
}
AI void add(int x, int y) {
	to[++ecnt] = y;
	nxt[ecnt] = g[x];
	g[x] = ecnt;
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	fa[s] = s;
	bfsinit(s);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y));
	}
	return 0;
}