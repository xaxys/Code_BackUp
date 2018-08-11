#include<bits/stdc++.h>
#define N 200010
#define lc (o << 1)
#define rc (o << 1 | 1)
#define m ((l + r) >> 1)
using namespace std;
class SegmentTree {
	int sumv[N << 2], setv[N << 2], v, _sum, qL, qR;
	inline void pushdown(int l, int r, int o);
	inline void update(int l, int r, int o);
	inline void query(int l, int r, int o);
public:
	inline void init();
	inline int query(int l, int r);
	inline void set(int l, int r, int v);
};
int n, q, x;
int depth[N], fa[N], son[N], siz[N], top[N];
int lft[N], rit[N];
int to[N], nxt[N], head[N], ecnt, cnt;
char s[100];
SegmentTree tree;
//void dfsinit(int x);
//void dfs(int x);
inline void bfsinit(int s);
inline int install(int x);
inline int uninstall(int x);
inline void addedge(int x, int y);
int main(int argc, char *argv) {
	//freopen("testdata.in", "r", stdin);
	//freopen("testdata.ans", "w", stdout);
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &fa[i]);
		fa[i]++;
		addedge(fa[i], i);
	}
	tree.init();
	//dfsinit(1); dfs(1);
	bfsinit(1);
	fa[1] = 1;
	scanf("%d", &q);
	while (q--) {
		scanf("%s%d", s, &x);
		if (s[0] == 'i') printf("%d\n", install(x + 1));
		else printf("%d\n", uninstall(x + 1));
	}
	return 0;
}
inline void SegmentTree::pushdown(int l, int r, int o) {
	if (setv[o] >= 0) {
		int M = m;
		setv[lc] = setv[o];
		setv[rc] = setv[o];
		sumv[lc] = (M - l + 1) * setv[o];
		sumv[rc] = (r - M) * setv[o];
		setv[o] = -1;
	}
}
inline void SegmentTree::update(int l, int r, int o) {
	if (qL <= l && r <= qR) {
		setv[o] = v;
		sumv[o] = (r - l + 1) * v;
		return;
	}
	pushdown(l, r, o);
	int M = m;
	if (qL <= M) update(l, M, lc);
	if (M < qR) update(M + 1, r, rc);
	sumv[o] = sumv[lc] + sumv[rc];
}
inline void SegmentTree::query(int l, int r, int o) {
	if (qL <= l && r <= qR) {
		_sum += sumv[o];
		return;
	}
	pushdown(l, r, o);
	int M = m;
	if (qL <= M) query(l, M, lc);
	if (M < qR) query(M + 1, r, rc);
}
inline void SegmentTree::init() {
		memset(setv, -1, sizeof(setv));
		memset(sumv, 0, sizeof(sumv));
}
inline int SegmentTree::query(int l, int r) {
		this->_sum = 0;
		this->qL = l;
		this->qR = r;
		query(1, n, 1);
		return _sum;
}
inline void SegmentTree::set(int l, int r, int v) {
		this->v = v;
		this->qL = l;
		this->qR = r;
		update(1, n, 1);
}
inline void bfsinit(int s) {
	int *q = new int[N], h = 0, t = 1;
	siz[s] = 1;
	q[1] = s;
	depth[1] = 1;
	while (h < t) {
		h++;
		int& x = q[h];
		for (int i = head[x]; i; i = nxt[i]) {
			int& u = to[i];
			depth[u] = depth[x] + 1;
			fa[u] = x;
			siz[u] = 1;
			q[++t] = u;
		}
	}
	for (int i = t; i >= 2; i--) {
		int& u = q[i], x = fa[u];
		siz[x] += siz[u];
		if (!son[x] || siz[son[x]] < siz[u]) son[x] = u;
	}
	for (int i = 1; i <= t; i++) {
		int& u = q[i];
		if (!top[u]) {
			int cnt = rit[fa[u]];
			for (int v = u; v; v = son[v]) {
				top[v] = u;
				lft[v] = ++cnt;
				rit[v] = cnt;
				rit[fa[v]] += siz[v];
			}
		}
	}
	delete[] q;
}
inline int install(int x) {
	int num = 0;
	while (top[x] != 1) {
		num += depth[x] - depth[top[x]] + 1 - tree.query(lft[top[x]], lft[x]);
		tree.set(lft[top[x]], lft[x], 1);
		x = fa[top[x]];
	}
	num += depth[x] - tree.query(1, lft[x]);
	tree.set(1, lft[x], 1);
	return num;
}
inline int uninstall(int x) {
	int num = tree.query(lft[x], rit[x]);
	tree.set(lft[x], rit[x], 0);
	return num;
}
inline void addedge(int x, int y) {
	to[++ecnt] = y;
	nxt[ecnt] = head[x];
	head[x] = ecnt;
}

/*void dfsinit(int x) {
	depth[x] = depth[fa[x]] + 1;
	siz[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		int& u = to[i];
		dfsinit(u);
		siz[x] += siz[u];
		if (!son[x] || siz[son[x]] < siz[u]) son[x] = u;
	}
}
void dfs(int x) {
	if (!top[x]) top[x] = x;
	lft[x] = ++cnt;
	if (son[x]) {
		top[son[x]] = top[x];
		dfs(son[x]);
	}
	for (int i = head[x]; i; i = nxt[i]) {
		int &u = to[i];
		if (u == son[x]) continue;
		dfs(u);
	}
	rit[x] = cnt;
}*/