#include<cstdio>
#include<cstring>
#include<algorithm>
#include<list>
#define N 10010
#define M 100010
using namespace std;
typedef long long ll;
ll n, m, b, f[N], x, y, z, l, r, mid, ans = -1;
ll to[M], v[M], nxt[M], head[N], ecnt;
inline void addedge(ll x, ll y, ll z) {
	to[++ecnt] = y;
	v[ecnt] = z;
	nxt[ecnt] = head[x];
	head[x] = ecnt;
}
inline bool test() {
	ll d[N];
	bool vis[N];
	memset(d, 0x7f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[1] = 0;
	list<int> q;
	q.push_back(1);
	while (!q.empty()) {
		ll x = q.front();
		q.pop_front();
		vis[x] = 0;
		for (ll i = head[x]; i; i = nxt[i]) {
			ll& u = to[i];
			if (f[u] <= mid && d[u] > v[i] + d[x]) {
				d[u] = v[i] + d[x];
				if (!vis[u]) {
					vis[u] = 1;
					if (!q.empty() && d[u] < d[q.front()]) q.push_front(u);
					else q.push_back(u);
				}
			}
		}
	}
	return d[n] < b;
}
int main(){
	scanf("%lld%lld%lld", &n, &m, &b);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &f[i]);
		r = max(f[i], r);
	}
	for (ll i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &x, &y, &z);
		addedge(x, y, z);
		addedge(y, x, z);
	}
	while (l <= r) {
		mid = (l + r) >> 1;
		if (test()) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if(~ans) printf("%lld\n", ans);
	else puts("AFK");
	return 0;
}