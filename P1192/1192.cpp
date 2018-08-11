#include <iostream>
#include <string.h>
using namespace std;
int main() {
	int n, k, a[1000000],i;
	cin >> n >> k;
	memset(a, 0, sizeof(a));
	a[0] = a[1] = 1;
	for (i = 2; i <= k; i++) {
		a[i] = (a[i - 1] * 2) % 100003;
	}
	while (i <= n) {
		for (int j = i - 1; j >= i - k; j--) {
			a[i] = (a[i] + a[j]) % 100003;
		}
		i++;
	}
	cout << a[n] << endl;
	return 0;
}