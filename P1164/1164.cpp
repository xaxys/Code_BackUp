#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int m, n, price[101], dp[10001];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> price[i];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= price[i]; j--) {
			dp[j] += dp[j - price[i]];
		}
	}
	cout << dp[m] << endl;
	return 0;
}