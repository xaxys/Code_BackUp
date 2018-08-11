#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, t[1010], minn = 0x7f7f7f7f, g1[1010], g2[1010], upper[1010], lower[1010];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> t[i];
	memset(g1, 0x3f, sizeof(g1));
	memset(g2, 0x3f, sizeof(g2));
	for (int i = 1; i <= n; i++) {
		int k = lower_bound(g1 + 1, g1 + n + 1, t[i]) - g1;
		upper[i] = k;
		g1[k] = t[i];
	}
	for (int i = n; i > 0; i--) {
		int k = lower_bound(g2 + 1, g2 + n + 1, t[i]) - g2;
		lower[i] = k;
		g2[k] = t[i];
	}
	for (int i = 1; i <= n; i++) {
		minn = min(minn, i - upper[i] + n - i - lower[i] + 1);
	}
	cout << minn << endl;
	return 0;
}