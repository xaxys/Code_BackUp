#include<iostream> 
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<vector>
#define ll long long
#define p 1000000007
using namespace std;
ll cat[100010], n;
ll qpow(ll a, ll b) {
	ll r = 1, base = a;
	while (b) {
		if (b & 1) r = r * base % p;
		base = base * base % p;
		b >>= 1;
	}
	return r;
}
int main() {
	/*ll h[100010], n;
	h[0] = h[1] = 1;
	for (ll i = 2; i <= 10000; i++) {
		h[i] = 0;
		for (ll j = 0; j < i; j++)
			h[i] += (h[j]%p * h[i - 1 - j])%p;
	}*/
	//(catalan(n-1)*(4*n-2))div(n+1)
	cat[0] = 1;
	for (int i = 1; i <= 100010; i++) {
		cat[i] = (cat[i - 1] * (4 * i - 2)) % p * qpow(i + 1, p - 2) % p;
	}
	while (scanf("%lld", &n) == 1) printf("%lld\n", cat[n]);
	return 0;
}