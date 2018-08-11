#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100010
using namespace std;
int n, nxt[N], opt[N];
int color[N], dp[N], v[N], cnum;
int dfn[N], low[N], vis[N], dtime;
int sta[N], top;
void tarjan(int x) {
	sta[++top] = x;
	vis[x] = top;
	dfn[x] = low[x] = ++dtime;
	int& u = nxt[x];
	if (!dfn[u]) {
		tarjan(u);
		low[x] = min(low[x], low[u]);
	}
	else if (vis[u]) {
		low[x] = min(low[x], dfn[u]);
	}
	if (dfn[x] == low[x]) {
		cnum++;
		for (int k = vis[x]; top >= k; top--) {
			int& u = sta[top];
			color[u] = cnum;
			v[cnum]++;
			vis[u] = 0;
		}
	}
}
void dfs(int x) {
	dp[x] = v[x];
	if (opt[x]) {
		if (!dp[opt[x]]) dfs(opt[x]);
		dp[x] += dp[opt[x]];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &nxt[i]);
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++)
		if (color[i] != color[nxt[i]]) opt[color[i]] = color[nxt[i]];
	for (int i = 1; i <= cnum; i++)
		if (!dp[i]) dfs(i);
	for (int i = 1; i <= n; i++)
		printf("%d\n", dp[color[i]]);
	return 0;
}