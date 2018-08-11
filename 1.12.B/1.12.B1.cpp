#include<bits/stdc++.h>
using namespace std;
inline void read(int &x) {
	char c = getchar();
	int p = 1;
	x = 0;
	while (!isdigit(c)) {
		if (c == '-')p = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 1) + (x << 3) + (c^'0');
		c = getchar();
	}
	x *= p;
}//¿ì¶Á
const int maxn = 1000;
int head[maxn], tot, n, deep[maxn], sz[maxn], pre[maxn], ans, dis[maxn];
struct edge {
	int to, next;
}e[maxn << 1];
inline void add(int u, int v) {
	e[++tot].to = v;
	e[tot].next = head[u];
	head[u] = tot;
}
inline void dfs(int rt, int fa) {
	deep[rt] = deep[fa] + 1;
	for (register int i = head[rt]; i; i = e[i].next) {
		if (e[i].to == fa)continue;
		dfs(e[i].to, rt);
		pre[rt] += pre[e[i].to];
	}
}//dfsÔ¤´¦Àí
inline void dp(int rt, int fa) {
	for (register int i = head[rt]; i; i = e[i].next) {
		if (e[i].to == fa)continue;
		dis[e[i].to] = dis[rt] + pre[1] - pre[e[i].to] - pre[e[i].to];
		if (dis[e[i].to]<ans)ans = dis[e[i].to];
		dp(e[i].to, rt);
	}
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	for (register int i = 1; i <= n; ++i) {
		int a, b;
		read(sz[i]); read(a); read(b);
		pre[i] = sz[i];
		if (a) {
			add(i, a);
			add(a, i);
		}
		if (b) {
			add(i, b);
			add(b, i);
		}
	}
	deep[0] = 0;
	dfs(1, 0);
	for (register int i = 1; i <= n; ++i) {
		dis[1] += (deep[i] - 1)*sz[i];
	}
	ans = dis[1];
	dp(1, 0);
	cout << ans << endl;
	return 0;
}