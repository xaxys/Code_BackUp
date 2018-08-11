#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[10000];
void swap(int &a, int &b) {
	int t;
	t = a; a = b; b = t;
}
void next() {
	int small, k=n-1;
	while (a[k] < a[k - 1]) k--;
	for (small = n-1; small >= k; small--) {
		if (a[small] > a[k - 1]) break;
	}
	swap(a[small], a[k - 1]);
	sort(a + k, a + n);
}
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	while (m > 0) {
		next();
		m--;
	}
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}