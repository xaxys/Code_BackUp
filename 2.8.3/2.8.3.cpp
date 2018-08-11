#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll exgcd(ll l, ll r, ll &x, ll &y)
{
	if (r == 0) { x = 1; y = 0; return l; }
	else
	{
		ll d = exgcd(r, l%r, y, x);
		y -= l / r*x;
		return d;
	}
}
int main() {
	ll a, b, m;
	while (scanf("%lld%lld%lld", &a, &b, &m) == 3) {
		ll x, y, d = exgcd(a, b, x, y);
		x = (x%b + b) % b;
		y = (d - a*x) / b;
		for (; x*y != d || x < m; x = x + (b / d) && x>0 && y>0, y = y - (a / d));
		if (x < 0 || y < 0) printf("No answer\n");
		else printf("%lld\n", x, y);
	}
}