#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
string a, b;
int k, dp[2010][2010];
int dist(char a, char b) {
	return abs(a - b);
}
int main() {
	cin >> a >> b >> k;
	memset(dp, 0x7f, sizeof(dp));
	int la = a.length();
	int lb = b.length();
	dp[0][0] = 0;
	for (int i = 1; i <= la; i++) dp[i][0] = k + dp[i - 1][0];
	for (int i = 1; i <= lb; i++) dp[0][i] = k + dp[0][i - 1];
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + k;
			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + dist(a[i - 1], b[j - 1]));
		}
	}
	cout << dp[la][lb] << endl;
	return 0;
}