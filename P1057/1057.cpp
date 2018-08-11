#include <iostream>
#include <cstring>
using namespace std;
int n, m, a[31];

int left(int x) {
	if (x < n) return x + 1;
	return 1;
}
int right(int x) {
	if (x > 1) return x - 1;
	return n;
}
int main() {
	memset(a, 0, sizeof(a));
	a[1] = 1;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int tmp[31];
		memset(tmp, 0, sizeof(tmp));
		for (int j = 1; j <= n; j++) {
			if (a[j]) {
				tmp[left(j)] += a[j];
				tmp[right(j)] += a[j];
			}
		}
		for (int j = 1; j <= n; j++) a[j] = tmp[j];
	}
	cout << a[1] << endl;
	return 0;
}