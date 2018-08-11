#include<bits/stdc++.h>
#define P 100000007
typedef long long ll;
using namespace std;
int n, k;
int qpow(int x, int y, int p) {
	int r = 1, base = x;
	while (y) {
		if (y & 1) r = (ll)r * base %p;
		y >>= 1;
		base = (ll)base * base % p;
	}
	return r;
}
inline int chu(int x, int y) {
	return (ll)x * qpow(y, P - 2, P) % P;
}
int main() {
	scanf("%d%d", &n, &k);
	if (k == 0) printf("%d", chu(1, n));
	else {
		int a = 1, b = n - 1;
		a = chu(a, n), b = chu(b, n);
		for (int i = 1; i <= k - 1; i++) {
			int t = a;
			a = chu(b, n - 1 - i);
			b = chu(((ll)b * (n - 2 - i) + (ll)t * (n - 1 - i))% P, n - 1 - i);
		}
		printf("%d\n", b);
	}
	return 0;
}