#include<cstdio>
#include<cstring>
#include<algorithm>
#define lc minv[i << 1]
#define rc minv[i << 1 | 1]
#define pushup minv[i] = d[lc] < d[rc] ? lc : rc
#define N 100010
#define M 500010
#define INF 0x7fffffff
int n, m, s, L, minv[N << 2], d[N];
int to[M], nxt[M], v[M], head[N], ecnt;
/*
char ch[20000000]; int now_r, now_w = -1;
inline void read(int &x) {
	while (ch[now_r]<48) ++now_r;
	for (x = ch[now_r] - 48; ch[++now_r] >= 48;)
		x = (x << 1) + (x << 3) + ch[now_r] - 48;
}
int q2[500000], tail2;
void write(int x) {
	do { q2[++tail2] = x % 10; x /= 10; } while (x);
	for (; tail2; --tail2) ch[++now_w] = q2[tail2] + 48;
	ch[++now_w] = ' ';
}
*/
inline void addedge(int& x, int& y, int& z) {
	to[++ecnt] = y;
	v[ecnt] = z;
	nxt[ecnt] = head[x];
	head[x] = ecnt;
}
inline void init() {
	for (L = 1; L < n; L <<= 1);
	for (int i = 1; i <= n; i++) minv[i + L - 1] = i;
	for (int i = L - 1; i; i--) pushup;
}
inline void update(int x) {
	for (int i = x + L - 1 >> 1; i; i >>= 1) pushup;
}
void dijkstra() {
	for (int i = 0; i <= n; i++) d[i] = INF;
	d[s] = 0;
	init();
	for (int x = minv[1]; d[x] != INF; x = minv[1]) {
		minv[x + L - 1] = 0;
		update(x);
		for (int i = head[x]; i; i = nxt[i]) {
			int& u = to[i];
			if (d[x] + v[i] < d[u]) {
				d[u] = d[x] + v[i];
				update(u);
			}
		}
	}
}
int main() {
	//ch[fread(ch, 1, 20000000, stdin)] = 0;
	//read(n), read(m), read(s);
	scanf("%d%d%d", &n, &m, &s);
	int x, y, z;
	while (m--) {
		//read(x), read(y), read(z);
		scanf("%d%d%d", &x, &y, &z);
		addedge(x, y, z);
	}
	dijkstra();
	for (int i = 1; i <= n; i++)
		//write(d[i]);
		printf("%d ", d[i]);
	//fwrite(ch, 1, now_w, stdout);
	return 0;
}
