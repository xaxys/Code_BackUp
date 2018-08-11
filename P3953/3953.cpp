#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define N 100010
#define M 200010
#define clear(a) memset(a, 0, sizeof(a))
using namespace std;
int t, n, m, k, p;
int to[M], nxt[M], v[M], head[N], ecnt;
int To[M], Nxt[M], V[M], Head[N];
int dp[N][60], d[N];
bool flag, rec[N][60];
inline void addedge(int x, int y, int z) {
	to[++ecnt] = y;
	nxt[ecnt] = head[x];
	head[x] = ecnt;
	v[ecnt] = z;

	To[ecnt] = x;
	Nxt[ecnt] = Head[y];
	Head[y] = ecnt;
	V[ecnt] = z;
}
inline void spfa(int s) {
	d[s] = 0;
	int* q = new int[N << 4], h = 0, t = 1;
	int vis[N];
	clear(vis);
	q[1] = s;
	while (h < t) {
		int x = q[++h];
		vis[x] = 0;
		for (int i = head[x]; i; i = nxt[i]) {
			int u = to[i];
			if (d[u] > d[x] + v[i]) {
				d[u] = d[x] + v[i];
				if (!vis[u]) {
					vis[u] = 1;
					q[++t] = u;
				}
			}
		}
	}
}
void dfs(int x, int kk) {
	rec[x][kk] = 1;
	int& ans = dp[x][kk];
	ans = 0;
	for (int i = Head[x]; i; i = Nxt[i]) {
		int& u = To[i];
		int dist = kk - (V[i] + (d[u] - d[x]));
		if (dist < 0) continue;
		if (rec[u][dist]) {
			flag = 1; return;
		}
		if (!(~dp[u][dist])) dfs(u, dist);
		ans = (ans + dp[u][dist]) % p;
	}
	rec[x][kk] = 0;
}
inline void program() {
	memset(d, 0x7f, sizeof(d));
	memset(dp, -1, sizeof(dp));
	clear(to), clear(nxt), clear(head);
	clear(To), clear(Nxt), clear(Head);
	clear(rec);
	ecnt = 0, flag = 0;
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		addedge(x, y, z);
	}
	spfa(1);
	int a = 0;
	dp[1][0] = 1;
	for (int i = 0; i <= k; i++) {
		dfs(n, i);
		a = (a + dp[n][i]) % p;
	}
	dfs(n, k + 1);
	if (flag) printf("-1\n");
	else printf("%d\n", a);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("park8.in", "r", stdin);
	//freopen("park.out", "w", stdout);
#endif
	scanf("%d", &t);
	while (t--) program();
	return 0;
}