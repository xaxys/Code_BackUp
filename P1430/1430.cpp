#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1010
#define CLR(x) memset(x, 0, sizeof(x))
#define SUM(a, b) (pre[b] - pre[a - 1])
using namespace std;
int T, n, a[N], dp[N][N], f[N][N], g[N][N], pre[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		CLR(dp); CLR(f); CLR(g);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			pre[i] = pre[i - 1] + a[i];
			dp[i][i] = f[i][i] = g[i][i] = a[i];
		}
		for (int l = 1; l < n; l++) {
			for (int i = 1, j = i + l; j <= n; i++, j++) {
				dp[i][j] = SUM(i, j) - min(min(f[i + 1][j], g[i][j - 1]), 0);
				f[i][j] = min(f[i + 1][j], dp[i][j]);
				g[i][j] = min(g[i][j - 1], dp[i][j]);
			}
		}
		printf("%d\n", dp[1][n]);
	}
	return 0;
}