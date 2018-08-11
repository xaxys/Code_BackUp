#include<bits/stdc++.h>
#define mod 10007
using namespace std;
typedef long long ll;
ll qpow(ll a, ll b) {
	ll r = 1, base = a;
	while (b) {
		if (b & 1) r = r * base % mod;
		base = base * base % mod;
		b >>= 1;
	}
	return r;
}
ll C(ll m, ll n) {
	if (n > m / 2) n = m - n;
	ll x = 1, y = 1;
	for (ll i = m; i > m - n; i--) x = x * i % mod;
	for (ll i = 2; i <= n; i++) y = y * i % mod;
	return qpow(y, mod - 2) * x % mod;
}
ll a, b, k, m, ans;
int main() {
	scanf("%lld%lld%lld%lld", &a, &b, &k, &m);
	printf("%lld\n", C(k, m) * qpow(a, m) % mod * qpow(b, k - m) % mod);
	return 0;
}
