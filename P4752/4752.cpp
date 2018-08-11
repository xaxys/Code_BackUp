#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
map<ll, int> s;
int t, m, n;
ll x;
bool isprime(ll x) {
	for (ll i = 2; i * i <= x; i++) if (x % i == 0) return 0;
	return 1;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		s.clear();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x);
			if (x != 1) s[x]++;
		}
		for (int i = 1; i <= m; i++) {
			scanf("%lld", &x);
			if (x != 1) {
				if (s[x] == 1) s.erase(x);
				else s[x]--;
			}
		}
		printf(s.size() == 1 && s.begin()->second == 1 && isprime(s.begin()->first) ? "YES" : "NO");
		putchar(10);
	}
	return 0;
}