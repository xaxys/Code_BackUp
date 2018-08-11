#include<iostream>
#include<cstring>
using namespace std;
int c[500010], n, m;
void add(int x, int y) {
	while (x <= n) {
		c[x] += y;
		x += x&-x;
	}
}
int sum(int x) {
	int ans = 0;
	while (x > 0) {
		ans += c[x];
		x -= x&-x;
	}
	return ans;
}
int main() {
	memset(c, 0, sizeof(c));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		add(i, x);
	}
	while (m--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) add(x, y);
		else cout << sum(y)-sum(x-1) << endl;
	}
	return 0;
}