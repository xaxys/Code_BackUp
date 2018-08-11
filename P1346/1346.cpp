#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 110
#define M 10010
int n, a, b;
int head[N], to[M], nxt[M], v[M], ecnt;
int d[N], minv[N << 2], L;
bool done[N];
inline void addedge(int x, int y, int z) {
	to[++ecnt] = y;
	nxt[ecnt] = head[x];
	v[ecnt] = z;
	head[x] = ecnt;
}
void dijkstra() {
#define lc minv[i << 1]
#define rc minv[i << 1 | 1]
#define pushup minv[i] = d[lc] < d[rc] ? lc : rc
#define update(x) for (int i = L + x - 1 >> 1; i; i >>= 1) pushup;
	memset(d, 0x7f, sizeof(d));
	d[a] = 0;
	for (L = 1; L < n; L <<= 1);
	for (int i = 1; i <= n; i++) minv[L + i - 1] = i;
	for (int i = L - 1; i; i--) pushup;
	for (int i = 1; i <= n; i++) {
		int x = minv[1];
		if (done[x]) continue;
		minv[L + x - 1] = 0;
		update(x);
		done[x] = 1;
		for (int i = head[x]; i; i = nxt[i]) {
			int &u = to[i];
			if (!done[u] && d[u] > d[x] + v[i]) {
				d[u] = d[x] + v[i];
				update(u);
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		int k, x;
		scanf("%d", &k);
		if (!k) continue;
		scanf("%d", &x);
		addedge(i, x, 0);
		for (int j = 2; j <= k; j++) {
			scanf("%d", &x);
			addedge(i, x, 1);
		}
	}
	dijkstra();
	printf("%d\n", done[b] ? d[b] : -1);
	return 0;
}