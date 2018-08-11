#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int v[5][5] = {
	{5, -1, -2, -1, -3},
	{-1, 5, -3, -2, -4},
	{-2, -3, 5, -2, -2},
	{-1, -2, -2, 5, -1},
	{-3, -4, -2, -1, 0}
};
int a[120], b[120], na, nb, dp[120][120];
char ch;
int main() {
	memset(dp, -0x7f, sizeof(dp));
	dp[0][0] = 0;
	scanf("%d", &na);
	ch = getchar();
	ch = getchar();
	for (int i = 1; i <= na; i++, ch = getchar()) {
		switch (ch) {
		case 'A': a[i] = 0; break;
		case 'C': a[i] = 1; break;
		case 'G': a[i] = 2; break;
		case 'T': a[i] = 3; break;
		}
	}
	scanf("%d", &nb);
	ch = getchar();
	ch = getchar();
	for (int i = 1; i <= nb; i++, ch = getchar()) {
		switch (ch) {
		case 'A': b[i] = 0; break;
		case 'C': b[i] = 1; break;
		case 'G': b[i] = 2; break;
		case 'T': b[i] = 3; break;
		}
	}
	for (int i = 1; i <= na; i++) 
		dp[i][0] = dp[i - 1][0] + v[a[i]][4];
	for (int i = 1; i <= nb; i++) 
		dp[0][i] = dp[0][i - 1] + v[4][b[i]];
	for (int i = 1; i <= na; i++) {
		for (int j = 1; j <= nb; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + v[a[i]][b[j]]);
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + v[4][b[j]]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + v[a[i]][4]);
		}
	}
	printf("%d\n", dp[na][nb]);
	return 0;
}