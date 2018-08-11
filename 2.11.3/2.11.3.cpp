#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, cha[1010], dp[1010][10010];
int main() {
	memset(dp, 0x7f, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		cha[i] = x - y;
	}
	dp[1][cha[1] + 5000] = 0;
	dp[1][-cha[1] + 5000] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 5000 - 5*n ; j <= 5000 + 5 * n; j++) {
			if (j + cha[i] >= 5000 - 5 * n && j + cha[i] <= 5000 + 5 * n) dp[i][j] = min(dp[i][j], dp[i - 1][j + cha[i]] + 1);
			if (j - cha[i] >= 5000 - 5 * n && j - cha[i] <= 5000 + 5 * n) dp[i][j] = min(dp[i][j], dp[i - 1][j - cha[i]]);
		}
	}
	int ans = 0x7f7f7f7f;
	int i = 5000, j = 5000;
	for (; i <= 10 * n; i++) if (dp[n][i] < ans) break;
	for (; j >= 0; j++) if (dp[n][j] < ans) break;
	ans = min(dp[n][i], dp[n][j]);
	cout << ans << endl;
}