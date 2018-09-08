#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 52
typedef long long ll;
using namespace std;
int n, c, watt[N], loc[N], pre[N];
int f[N][N][2];
void dbginfo() {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			printf("0: %10d, 1: %10d | ", f[i][j][0], f[i][j][1]);
			for (int k = 0; k <= j; k++) {
				if (k == i - 1) printf("%3c", '[');
				else if (k == i || k == j) printf("%3d", k == i ? i : j);
				else printf("%3c", ' ');
			}
			printf("]\n");
		}
	}
}
int main() {
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) scanf("%d%d", &loc[i], &watt[i]);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + watt[i];
	memset(f, 0x7f, sizeof(f));
	f[c][c][0] = f[c][c][1] = 0;
	for (int l = 1; l < n; l++) {
		for (int i = 1, j = i + l; j <= n; i++, j++){
		f[i][j][0] = min((ll)f[i + 1][j][0] + (loc[i + 1] - loc[i]) * (pre[n] - pre[j] + pre[i]),
			(ll)f[i + 1][j][1] + (loc[j] - loc[i]) * (pre[n] - pre[j] + pre[i]));
		f[i][j][1] = min((ll)f[i][j - 1][1] + (loc[j] - loc[j - 1]) * (pre[n] - pre[j - 1] + pre[i - 1]),
			(ll)f[i][j - 1][0] + (loc[j] - loc[i]) * (pre[n] - pre[j - 1] + pre[i - 1]));
		}
	}
	printf("%d\n", min(f[1][n][0], f[1][n][1]));
	return 0;
}