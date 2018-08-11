#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 10010
#define maxm 100010
#define clean(a) memset(a, 0, sizeof(a))
using namespace std;
int n, m, val[maxn], dp[maxn], val2[maxn], ans;
int head[maxn], to[maxm], nxt[maxm], ecnt;
int low[maxn], dfn[maxn], vis[maxn], dtime;
int efrom[maxm], eto[maxm];
int color[maxn], cnum;
int sta[maxn], top;
inline void addedge(int x, int y) {
	to[++ecnt] = y;
	nxt[ecnt] = head[x];
	head[x] = ecnt;
}
void tarjan(int x) {
	sta[++top] = x;
	vis[x] = top;
	dfn[x] = low[x] = ++dtime;
	for (int i = head[x]; i; i = nxt[i]) {
		int &u = to[i];
		if (!dfn[u]) {
			tarjan(u);
			low[x] = min(low[x], low[u]);
		}
		else if (vis[u])
			low[x] = min(low[x], dfn[u]);
	}
	if (dfn[x] == low[x]) {
		cnum++;
		for (int k = vis[x]; top >= k; top--) {
			int& u = sta[top];
			color[u] = cnum;
			val2[cnum] += val[u];
			vis[u] = 0;
		}
	}
}
void dfs(int x) {
	int maxx = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		int &u = to[i];
		if (!dp[u]) dfs(u);
		maxx = max(maxx, dp[u]);
	}
	dp[x] = maxx + val2[x];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &efrom[i], &eto[i]);
		addedge(efrom[i], eto[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	clean(head); clean(to);	clean(nxt);
	ecnt = 0;
	for (int i = 1; i <= m; i++) {
		if (color[efrom[i]] != color[eto[i]]) addedge(color[efrom[i]], color[eto[i]]);
	}
	for (int i = 1; i <= cnum; i++) {
		if (!dp[i]) {
			dfs(i);
			ans = max(ans, dp[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}