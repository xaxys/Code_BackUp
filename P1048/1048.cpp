#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t, m, dp[1010];
int main() {
	memset(dp, 0, sizeof(dp));
	cin >> t >> m;
	while (m--) {
		int t0, v;
		cin >> t0 >> v;
		for (int i = t; i >= t0 ; i++) {
			dp[i] = max(dp[i], dp[i - t0] + v);
		}
	}
	cout << dp[t] << endl;
	return 0;
}