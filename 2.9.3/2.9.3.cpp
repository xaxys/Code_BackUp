#include<iostream> 
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<vector>
#define ll long long
#define maxn 1000010
#define p 1000000009
using namespace std;
ll f[maxn];
pair<ll, ll> solve(ll a, ll b) {
	if (!a) {
		return make_pair(0, 1);
	}
	if (!(a % 2)) {//a为偶数
		pair<ll, ll> r = solve((a - 2) / 2, (b - 1) / 2);
		ll x = r.first, y = r.second, xx = (x*x%p + y*y%p) % p, yy = (2 * x%p + y %p) % p*y%p;
		return make_pair(yy, xx + yy);
	}
	else {//a为奇数
		pair<ll, ll> r = solve((a - 1) / 2, b / 2);
		ll x = r.first, y = r.second;
		return make_pair((x*x%p + y*y%p) % p, (2 * x%p + y %p) % p*y %p);
	}
}
int main() {
	ll n;
	while (scanf("%lld", &n) == 1) {
		if (!(n % 2)) {
			pair<ll, ll> r = solve(n - 1, n);
			printf("%lld\n", r.second % p);
		}
		else {
			pair<ll, ll> r = solve(n , n + 1);
			printf("%lld\n", r.first % p);
		}
	}
	return 0;
}