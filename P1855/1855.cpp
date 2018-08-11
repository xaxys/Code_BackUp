#include<iostream>
#include<algorithm>
using namespace std;
int n, m, t, mm[110], tt[110], dp[210][210];
int main() {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) cin >> mm[i] >> tt[i];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= mm[i]; j--) {
			for (int k = t; k >= tt[i]; k--) {
				dp[j][k] = max(dp[j][k], dp[j - mm[i]][k - tt[i]] + 1);
			}
		}
	}
	cout << dp[m][t] << endl;
	return 0;
}