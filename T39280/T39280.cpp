#include<bits/stdc++.h>
#define N 100010
typedef long long ll;
using namespace std;
ll n, x, y, ans;
ll a, b, c[N], ord[N];
ll dis[N];
bool cmp(ll a, ll b) { return dis[a] == dis[b] ? a < b : dis[a] < dis[b]; }
int main() {
	scanf("%lld%lld%lld", &n, &x, &y);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &a, &b, &c[i]);
		dis[i] = (a - x) * (a - x) + (b - y) * (b - y);
		ord[i] = i;
	}
	sort(ord + 1, ord + n + 1, cmp);
	ll red = 0, black = 0;
	for (ll i = 1; i <= n; i++) {
		if (c[ord[i]] == 1) red++;
		else black++;
		if (red >= black) ans++;
	}
	printf("%lld\n", ans);
	return 0;
}