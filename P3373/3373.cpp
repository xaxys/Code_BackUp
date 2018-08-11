#include<bits/stdc++.h>
#define N 100010
#define ini ll lc = (o << 1), rc = (o << 1 | 1), m = ((l + r) >> 1)
#define pushup sumv[o] = sumv[lc] + sumv[rc]
typedef long long ll;
using namespace std;
ll n, a[N], p, m, x, y, k, op;
class SegmentTree {
	ll addv[N << 2], mulv[N << 2], sumv[N << 2], setv[N << 2];
	ll qL, qR, v, _sum;
	inline void pushdown(ll l, ll r, ll o) {
		ini;
		if (setv[o] >= 0) {
			setv[lc] = setv[rc] = setv[o];
			addv[lc] = addv[rc] = 0;
			mulv[lc] = mulv[rc] = 1;
			sumv[lc] = (m - l + 1) * setv[o] % p;
			sumv[rc] = (r - m) * setv[o] % p;
			setv[o] = -1;
			return;
		}
		if (mulv[o] != 1) {
			mulv[lc] = (mulv[lc] * mulv[o]) % p;
			mulv[rc] = (mulv[rc] * mulv[o]) % p;
			addv[lc] = (addv[lc] * mulv[o]) % p;
			addv[rc] = (addv[rc] * mulv[o]) % p;
			sumv[lc] = (sumv[lc] * mulv[o]) % p;
			sumv[rc] = (sumv[rc] * mulv[o]) % p;
			mulv[o] = 1;
		}
		if (addv[o]) {
			addv[lc] = (addv[lc] + addv[o]) % p;
			addv[rc] = (addv[rc] + addv[o]) % p;
			sumv[lc] = (sumv[lc] + (m - l + 1) * addv[o] % p) % p;
			sumv[rc] = (sumv[rc] + (r - m) * addv[o] % p) % p;
			addv[o] = 0;
		}
	}
	void build(ll a[], ll l, ll r, ll o) {
		addv[o] = 0;
		mulv[o] = 1;
		setv[o] = -1;
		if (l == r) {
			sumv[o] = a[l];
			return;
		}
		ini;
		build(a, l, m, lc);
		build(a, m + 1, r, rc);
		pushup;
	}
	void jia(ll l, ll r, ll o) {
		if (qL <= l && r <= qR) {
			addv[o] = (addv[o] + v) % p;
			sumv[o] = (sumv[o] + v * (r - l + 1) % p) % p;
			return;
		}
		ini;
		pushdown(l, r, o);
		if (qL <= m) jia(l, m, lc);
		if (qR > m) jia(m + 1, r, rc);
		pushup;
	}
	void gai(ll l, ll r, ll o) {
		if (qL <= l && r <= qR) {
			setv[o] = v;
			sumv[o] = (v * (r - l + 1)) % p;
			return;
		}
		ini;
		pushdown(l, r, o);
		if (qL <= m) gai(l, m, lc);
		if (qR > m) gai(m + 1, r, rc);
		pushup;
	}
	void cheng(ll l, ll r, ll o) {
		if (qL <= l && r <= qR) {
			mulv[o] = mulv[o] * v % p;
			addv[o] = addv[o] * v % p;
			sumv[o] = sumv[o] * v % p;
			return;
		}
		ini;
		pushdown(l, r, o);
		if (qL <= m) cheng(l, m, lc);
		if (qR > m) cheng(m + 1, r, rc);
		pushup;
	}
	void query(ll l, ll r, ll o) {
		if (qL <= l && r <= qR) {
			_sum = (_sum + sumv[o]) % p;
			return;
		}
		ini;
		pushdown(l, r, o);
		if (qL <= m) query(l, m, lc);
		if (qR > m) query(m + 1, r, rc);
	}
public:
	inline void build(ll a[]) {
		build(a, 1, n, 1);
	}
	inline void add(ll l, ll r, ll v) {
		qL = l; qR = r; this->v = v;
		jia(1, n, 1);
	}
	inline void set(ll l, ll r, ll v) {
		qL = l; qR = r; this->v = v;
		gai(1, n, 1);
	}
	inline void mul(ll l, ll r, ll v) {
		qL = l, qR = r; this->v = v;
		cheng(1, n, 1);
	}
	inline ll query(ll l, ll r) {
		qL = l, qR = r, _sum = 0;
		query(1, n, 1);
		return _sum;
	}
};
SegmentTree sgt;
int main(int argc, char** argv) {
	scanf("%lld%lld%lld", &n, &m, &p);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sgt.build(a);
	while (m--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 3) {
			printf("%d\n", sgt.query(x, y));
		}
		else {
			scanf("%d", &k);
			if (op == 1) sgt.mul(x, y, k);
			else sgt.add(x, y, k);
		}
	}
	return 0;
}