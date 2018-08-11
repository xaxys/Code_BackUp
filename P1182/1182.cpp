#include <iostream>
using namespace std;
int m, n, maxn=0, total=0, a[100000];
bool judge(int mid) {
	int tmp = 0, ans=1;
	for (int i = 1; i <= n; i++) {
		if (tmp + a[i] <= mid) tmp += a[i];
		else {
			tmp = a[i];
			ans++;
		}
	}
	return ans > m;
}
void binary(int l, int r) {
	int mid = (l + r) / 2;
	if (l >= r) {
		cout << l << endl;
		exit(0);
	}
	if (judge(mid)) binary(mid + 1, r);
	else binary(l, mid);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		total += a[i];
		if (a[i] > maxn) maxn = a[i];
	}
	binary(maxn, total);
}