#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, a[2010], dp[2010], maxa = 0;
int gcd(int a, int b) {
	return (!b) ? a : gcd(b, a%b);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j < i; j++) {
			if (gcd(a[i], a[j]) > 1)
				//if (a[j] == 1 || a[i] == 1) ans = max(ans, dp[j]);
				ans = max(ans, dp[j] + 1);
		}
		dp[i] = ans;
	}
	for (int i = 1; i <= n; i++) maxa = max(maxa, dp[i]);
	cout << maxa << endl;
	return 0;
}