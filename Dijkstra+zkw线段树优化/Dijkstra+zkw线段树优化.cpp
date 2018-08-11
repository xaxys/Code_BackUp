#include<cstdio>
#include<cstring>
#include<algorithm>
#define lc minv[i << 1]
#define rc minv[i << 1 | 1]
#define N 10010
#define M 500010
#define INF 0x7fffffff
int n, m, s, L, minv[N << 2], d[N];
int to[M], nxt[M], v[M], head[N], ecnt;
inline void init() {
	for (L = 1; L < n; L <<= 1);
	for (int i = 1; i <= n; i++) minv[i + L - 1] = i;
	for (int i = L - 1; i; i--) minv[i] = d[lc] < d[rc] ? lc : rc;
}
inline void update(int x) {
	for (int i = x + L - 1 >> 1; i; i >>= 1) minv[i] = d[lc] < d[rc] ? lc : rc;
}
inline void addedge(int& x, int& y, int& z) {
	to[++ecnt] = y;
	v[ecnt] = z;
	nxt[ecnt] = head[x];
	head[x] = ecnt;
}
void dijkstra() {
	bool done[N];
	memset(done, 0, sizeof(done));
	for (int i = 0; i <= n; i++) d[i] = INF;
	d[s] = 0;
	init();
	for(int i = 1; i <= n; i++) {
		int x = minv[1];
		done[x] = 1;
		minv[x + L - 1] = 0;
		update(x);
		for (int i = head[x]; i; i = nxt[i]) {
			int& u = to[i];
			if (!done[u] && d[x] + v[i] < d[u]) {
				d[u] = d[x] + v[i];
				update(u);
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	while (m--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		addedge(x, y, z);
	}
	dijkstra();
	for (int i = 1; i <= n; i++) printf("%d ", d[i]);
	return 0;
}
