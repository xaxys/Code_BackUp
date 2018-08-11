/*
#include<cstdio>
#include<algorithm>
#define N 500010
typedef long long ll;
using namespace std;
ll n, m, q, x, y;
struct node {
	node *fa, *ch[2];
	ll l, r, siz;
	node (ll a, ll b) : l(a), r(b) {
		siz = b - a + 1;
		fa = ch[0] = ch[1] = nullptr;
	}
};
class Splay {
	node *root = nullptr;
	inline ll getp(const node *x) const {
		return x->fa->ch[1] == x;
	}
	inline void pushup(node *x) {
		x->siz = x->r - x->l + 1;
		if (x->ch[0] != nullptr) x->siz += x->ch[0]->siz;
		if (x->ch[1] != nullptr) x->siz += x->ch[1]->siz;
	}
	inline void rotate(node* x) {
		node *fa = x->fa, *grd = fa->fa;
		ll pos = getp(x);
		x->fa = grd;
		if (grd != nullptr) grd->ch[getp(fa)] = x;
		fa->ch[pos] = x->ch[pos ^ 1];
		if (x->ch[pos ^ 1]) x->ch[pos ^ 1]->fa = fa;
		fa->fa = x;
		x->ch[pos ^ 1] = fa;
		pushup(fa);
		pushup(x);
	}
	inline void splay(node *x, node *target) {
		for (; x->fa != target; rotate(x)) {
			if (x->fa->fa != target) {
				rotate(getp(x->fa) == getp(x) ? x->fa : x);
			}
		}
		if (target == nullptr) root = x;
	}
	inline void split(node *x, ll k) {
		splay(x, nullptr);
		k += x->l - 1;
		node *tmp = new node(k + 1, x->r);
		x->r = k - 1;
		if (x->ch[1] != nullptr) {
			x->ch[1]->fa = tmp;
			tmp->ch[1] = x->ch[1];
		}
		x->ch[1] = tmp;
		tmp->fa = x;
		pushup(tmp);
		pushup(x);
	}
public:
	void push_back(node *x) {
		if (root == nullptr) { root = x; return; }
		node* last = root;
		while (last->ch[1] != nullptr) last = last->ch[1];
		last->ch[1] = x;
		x->fa = last;
		splay(x, nullptr);
	}
	inline ll pop(ll k) {
		node* x = root;
		ll szl = 0, szm = x->r - x-> l + 1;
		if (x->ch[0]) szl = x->ch[0]->siz;
		while ("YES! Splay!") {
			if (k <= szl) 
				x = x->ch[0];
			else if ((k -= szl) <= szm) {
				split(x, k);
				return k + x->l - 1;
			}
			else {
				k -= x->r - x->l + 1;
				x = x->ch[1];
			}
		}
	}
};
Splay t[N], p;
ll main() {
	scanf("%d%d%d", &n, &m, &q);
	for (ll i = 1; i <= n; i++) {
		t[i].push_back(new node((i - 1) * m + 1, i * m - 1));
		p.push_back(new node(i*m, i*m));
	}
	while (q--) {
		scanf("%d%d", &x, &y);
		ll tmp;
		if (y == m) {
			printf("%d\n", tmp = p.pop(x));
			p.push_back(new node(tmp, tmp));
		}
		else {
			printf("%d\n", tmp = t[x].pop(y));
			p.push_back(new node(tmp, tmp));
			ll tmp2 = p.pop(x);
			t[x].push_back(new node(tmp2, tmp2));
		}
	}
	return 0;
}
*/
#include<cstdio>
#include<algorithm>
#define N 300010
#define NN N << 5
#define getp(x) (ch[fa[x]][1] == x)
typedef long long ll;
using namespace std;
int n, m, q, x, y;
class Splay {
	int rt[N], cnt = 0, *root = nullptr;
	ll l[NN], r[NN], siz[NN];
	int fa[NN], ch[NN][2];
	inline int newNode(ll a, ll b) {
		siz[++cnt] = b - a + 1;
		l[cnt] = a, r[cnt] = b;
		fa[cnt] = ch[cnt][0] = ch[cnt][1] = 0;
		return cnt;
	}
	inline void pushup(int x) {
		siz[x] = r[x] - l[x] + 1;
		if (ch[x][0]) siz[x] += siz[ch[x][0]];
		if (ch[x][1]) siz[x] += siz[ch[x][1]];
	}
	inline void rotate(int x) {
		int fat = fa[x], grd = fa[fat];
		int pos = getp(x);
		fa[x] = grd;
		if (grd) ch[grd][getp(fat)] = x;
		ch[fat][pos] = ch[x][pos ^ 1];
		if (ch[x][pos ^ 1]) fa[ch[x][pos ^ 1]] = fat;
		fa[fat] = x;
		ch[x][pos ^ 1] = fat;
		pushup(fat);
		pushup(x);
	}
	inline void splay(int x, int target) {
		for (; fa[x] != target; rotate(x)) {
			if (fa[fa[x]] != target) {
				rotate(getp(fa[x]) == getp(x) ? fa[x] : x);
			}
		}
		if (!target) *root = x;
	}
	inline void split(int x, ll k) {
		splay(x, 0);
		k += l[x] - 1;
		int tmp = newNode(k + 1, r[x]);
		r[x] = k - 1;
		if (ch[x][1]) {
			fa[ch[x][1]] = tmp;
			ch[tmp][1] = ch[x][1];
		}
		ch[x][1] = tmp;
		fa[tmp] = x;
		pushup(tmp);
		pushup(x);
	}
public:
	inline void setroot(int rtn, ll a, ll b) {
		int tmp = newNode(a, b);
		rt[rtn] = tmp;
	}
	inline void push_back(int rtn, ll x) {
		root = &rt[rtn];
		int tmp = newNode(x, x), last = *root;
		while (ch[last][1]) last = ch[last][1];
		ch[last][1] = tmp;
		fa[tmp] = last;
		splay(tmp, 0);
	}
	inline ll pop(int rtn, ll k) {
		root = &rt[rtn];
		int x = *root;
		while ("I Love Splay!") {
			ll szl = siz[ch[x][0]], szm = r[x] - l[x] + 1;
			if (k <= szl)
				x = ch[x][0];
			else if ((k -= szl) <= szm) {
				split(x, k);
				return k + l[x] - 1;
			}
			else {
				k -= szm;
				x = ch[x][1];
			}
		}
		return 0;
	}
};
Splay S;
int main() {
	//freopen("phalanx20.in", "r", stdin);
	//freopen("phalanx20.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	S.setroot(n + 1, m, m);
	for (ll i = 1; i <= n; i++) S.setroot(i, (i - 1) * m + 1, i * m - 1);
	for (ll i = 2; i <= n; i++) S.push_back(n + 1, i * m);
	while (q--) {
		scanf("%d%d", &x, &y);
		ll tmp;
		if (y == m) {
			printf("%lld\n", tmp = S.pop(n + 1, x));
			S.push_back(n + 1, tmp);
		}
		else {
			printf("%lld\n", tmp = S.pop(x, y));
			S.push_back(n + 1, tmp);
			ll tmp2 = S.pop(n + 1, x);
			S.push_back(x, tmp2);
		}
	}
	return 0;
}
