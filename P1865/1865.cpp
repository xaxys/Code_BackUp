#include <iostream>
using namespace std;
int main() {
	bool b[1000000] = { true };
	int a[80000], n, m, i = 2, k = -1;
	memset(b, 1, sizeof(b));
	//for (int o = 2; o < 1000000; o++) b[o] = true;
	while (i < 1000000) {
		if (b[i] == true) {
			a[++k] = i;
			int j = 2*i;
			while(j<1000000){
				b[j] = false;
				j += i;
			}
		}
		i++;
	}
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		int l, r, j = 0, ans = 0;
		cin >> l >> r;
		if (l >= 1 && r <= m) {
			while (j <= k) {
				if (a[j] >= l) {
					if (a[j] <= r) ans++;
					else break;
				}
				j++;
			}
		}
		else {
			cout << "Crossing the line" << endl;
			continue;
		}
		cout << ans << endl;
	}
	return 0;
}
