#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
ll n, m, ans = 1;
vector<ll> a;
int main() {
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	if (a.front() != 1) {
		printf("No answer!!!\n");
		return 0;
	}
	auto it = a.begin();
	for (ll maxx = 1; maxx < m && it != a.end(); it++) {
		if (*it > maxx + 1) {
			ll nxt = *it, pre = *(it - 1);
			ll num = (nxt - 1 - maxx) % pre == 0 ? (nxt - 1 - maxx) / pre : (nxt - 1 - maxx) / pre + 1;
			ans += num;
			maxx += pre * num;
		}
		if (it + 1 == a.end()) {
			ll num = (m - maxx) % *it == 0 ? (m - maxx) / *it : (m - maxx) / *it + 1;
			ans += num;
			maxx += *it * num;
		}
	}
	printf("%lld\n", ans);
	return 0;
}