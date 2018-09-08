#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 2010
using namespace std;
int n, m, g[N][N], f[N][N], maxsq, maxrtg;
struct p {
	int idx, width;
	p(int a = 0, int b = 0) : idx(a), width(b) {}
} sta[N];
int top;
inline void getf() {
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (g[i][j]) f[i][j] = f[i][j - 1] + 1;
		}
	}
}
int sqr(int x) { return x * x; }
inline void calc() {
	getf();
	for (int j = 1; j <= m; j++) {
		top = 0;
		for (int i = 1; i <= n + 1; i++) {
			int midx = i;
			while (top && f[i][j] <= sta[top].width) {
				p tmp = sta[top--];
				maxsq = max(maxsq, sqr(min(tmp.width, i - tmp.idx)));
				maxrtg = max(maxrtg, tmp.width * (i - tmp.idx));
				midx = tmp.idx;
			}
			sta[++top] = p(midx, f[i][j]);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &g[i][j]);
			g[i][j] ^= (i - j) & 1;
		}
	}
	calc();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			g[i][j] ^= 1;
		}
	}
	calc();
	printf("%d\n%d\n", maxsq, maxrtg);
	return 0;
}