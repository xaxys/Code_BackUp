#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100010
#define getp(x) (ch[f[x]][1] == x)
using namespace std;
int n, a[N];
class Splay {
	int data[N], f[N], ch[N][2], siz[N];
	int root, sz;
	int sumv[N], addv[N], rev[N];
	inline void pushup(int x) {
		sumv[x] = sumv[ch[x][0]] + sumv[ch[x][1]] + data[x];
		siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
	}
	inline void pushdown(int x) {
		if (rev[x]) {
			swap(ch[x][0], ch[x][1]);
			if (ch[x][0]) rev[ch[x][0]] ^= 1;
			if (ch[x][1]) rev[ch[x][1]] ^= 1;
			rev[x] = 0;
		}
		if (addv[x]) {
			data[x] += addv[x];
			if (ch[x][0]) addv[ch[x][0]] += addv[x];
			if (ch[x][1]) addv[ch[x][1]] += addv[x];
			addv[x] = 0;
		}
	}
	inline void rotate(int x) {
		int fa = f[x], grand = f[f[x]], pos = getp(x);
		f[x] = grand;
		if (grand) ch[grand][getp(fa)] = x;
		ch[fa][pos] = ch[x][pos ^ 1];
		f[ch[x][pos ^ 1]] = fa;
		f[fa] = x;
		ch[x][pos ^ 1] = fa;
	}
	inline void splay(int x, int target) {
		for (; f[x] != target; rotate(x)) {
			if (f[f[x]] != target) {
				rotate(getp(x) == getp(f[x]) ? f[x] : x);
			}
		}
		if (!target) root = x;
	}
	inline void findkth(int x, int kth) {

	}
	inline int build(int l, int r, int fa, int a[]) {
		if (l > r) return 0;
		if (l == r) {
			siz[l] = 1;
			f[l] = fa;
			data[l] = a[l];
			return l;
		}
		int m = l + r >> 1;
		f[m] = fa;
		ch[m][0] = build(l, m - 1, m, a);
		ch[m][1] = build(m + 1, r, m, a);
		pushup(m);
		return m;
	}
public:
	inline void build(int a[]) {
		build(1, n, 0, a);
	}
	inline void 
};