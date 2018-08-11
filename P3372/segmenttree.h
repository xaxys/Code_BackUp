#ifndef __SEGMENTTREE_H__
#define __SEGMENTTREE_H__
#include<bits/stdc++.h>
#define ll long long
#define maxnode 500010
ll n, m, op, qL, qR, v, a[maxnode];
class SegmentTree {
	ll sumv[maxnode << 1], addv[maxnode << 1], _sum;
	inline void query(ll l, ll r, ll o) {
		if (qL <= l && r <= qR) _sum += sumv[o];
		else {
			pushdown(l, r, o);
			ll m = (r + l) >> 1;
			if (qL <= m) query(l, m, o << 1);
			if (m < qR) query(m + 1, r, o << 1 | 1);
		}
	}
	inline void pushdown(ll l, ll r, ll o) {
		if (addv[o]) {
			ll m = (l + r) >> 1, lc = o << 1, rc = o << 1 | 1;
			addv[lc] += addv[o];
			addv[rc] += addv[o];
			sumv[lc] += addv[o] * (m - l + 1);
			sumv[rc] += addv[o] * (r - m);
			addv[o] = 0;
		}
	}
public:
	inline void build(const ll a[], ll l, ll r, ll o) {
		if (l == r) {
			sumv[o] = a[l];
			return;
		}
		ll m = (l + r) >> 1, lc = o << 1, rc = o << 1 | 1;
		build(a, l, m, lc);
		build(a, m + 1, r, rc);
		sumv[o] = sumv[lc] + sumv[rc];
	}
	inline void update(ll l, ll r, ll o) {
		ll lc = o << 1, rc = o << 1 | 1;
		if (qL <= l && r <= qR) {
			addv[o] += v;
			sumv[o] += v * (r - l + 1);
		}
		else {
			pushdown(l, r, o);
			ll m = (l + r) >> 1;
			if (qL <= m) update(l, m, lc);
			if (m < qR) update(m + 1, r, rc);
			sumv[o] = sumv[lc] + sumv[rc];
		}
	}
	inline ll query(ll l, ll r) {
		qL = l, qR = r;
		this->_sum = 0;
		query(1, n, 1);
		return _sum;
	}
};
SegmentTree tree;
int smain() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	tree.build(a, 1, n, 1);
	while (m--) {
		scanf("%lld%lld%lld", &op, &qL, &qR);
		if (op == 1) {
			scanf("%lld", &v);
			tree.update(1, n, 1);
		}
		else {
			printf("%lld\n", tree.query(1, n));
		}
	}
	return 0;
}
#endif