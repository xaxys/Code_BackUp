#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m, dp[1<<21][20], map[20][20];
int main() {
	memset(dp, 0x7f, sizeof(dp));
	memset(map, 0x7f, sizeof(map));
	cin >> n >> m ;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		map[x][y] = min(map[x][y], z);
		map[y][x] = min(map[y][x], z);
	}
	for (int i = 0; i < n; i++) dp[1 << i][i] = 0;
	for (int i = 0; i < 1 << n; i++)
		for (int j = 0; j < n; j++) 
			if (i & (1 << j)){
				for (int k = 0; k < n; k++) 
					if (!(i & (1 << k))){
						dp[i | 1 << k][k] = min(dp[i | 1 << k][k], dp[i][j] + map[j][k]);
					}
			}
	int ans = 0;
	for (int i = 0; i < n; i++) ans = min(ans, dp[(1 << n) - 1][i]);
	cout << ans << endl;
}