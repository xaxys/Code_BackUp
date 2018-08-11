#include <iostream>
using namespace std;
int a[50000], n, ans = 0;
void mergesort(int l, int r, int m) {
	int tmp[50000], r1 = l, r2 = m + 1, t = 0;
	while (r1 <= m&&r2 <= r) {
		if (a[r1] > a[r2]) {
			tmp[++t] = a[r2];
			r2++;
		}
		else {
			tmp[++t] = a[r1];
			r1++;
			ans += r2 - m - 1;
		}
	}
	if (r1 > m) for (int i = r2; i <= r; i++) tmp[++t] = a[i];
	else for (int i = r1; i <= m; i++) {
		tmp[++t] = a[i];
		ans += r2 - m - 1;
	}
	for (int i = 1; i <= t; i++) a[l + i - 1] = tmp[i];
}
void merge(int l, int r) {
	if (l == r) return;
	int m = (l + r) / 2;
	merge(l, m);
	merge(m + 1, r);
	mergesort(l, r, m);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	merge(1, n);
	cout << ans << endl;
	return 0;
}