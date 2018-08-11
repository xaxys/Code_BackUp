#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll exgcd(ll a, ll b, ll& x, ll& y) {
	if (!b) {
		x = 1;
		y = 0;
		return 1;
	}
	ll d = exgcd(b, a%b, y, x);
	y -= a / b*x;
	return d;
}
int main() {

	return 0;
}
