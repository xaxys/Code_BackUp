#include <iostream>
using namespace std;
int main() {
	int n, m, i, j, a[101];
	cin >> n >> m;
	if (n > 0) {
		for (i = 1; i < n; i++) {
			a[i] = i + 1;
		}
		a[n] = 1; a[0] = 1;
		i = 0;
		while (a[i] != i) {
			for (j = 0; j < m - 1; j++) {
				i = a[i];
			}
			cout << a[i] << " ";
			a[i] = a[a[i]];
		}
		cout << a[i];
	}
	return 0;
}