#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100010], n = 0;
void question1() {
	int g[100010], maxn = 0;
	memset(g, 0x7f, sizeof(g));
	for (int i = 0; i < n; i++) {
		int k = upper_bound(g + 1, g + n + 1, a[i]) - g;
		maxn = max(maxn, k);
		g[k] = a[i];
	}
	cout << maxn << endl;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	question1();
	return 0;
}