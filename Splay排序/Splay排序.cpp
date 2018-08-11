//P1177¡¾Ä£°å¡¿¿ìËÙÅÅÐò
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100010
using namespace std;
class Splay {
	int data[N], f[N], ch[N][2];
	int root, sz;
	inline int getp(int x) const {
		return ch[f[x]][1] == x;
	}
	inline void rotate(int x) {
		int fa = f[x], grand = f[f[x]], pos = getp(x);
		f[x] = grand;
		if (grand) ch[grand][getp(fa)] = x;
		ch[fa][pos] = ch[x][pos ^ 1];
		if (ch[x][pos ^ 1]) f[ch[x][pos ^ 1]] = fa;
		f[fa] = x;
		ch[x][pos ^ 1] = fa;
	}
	inline void splay(int x, int target) {
		for (; f[x] != target; rotate(x)) {
			if (f[f[x]] != target) {
				rotate(getp(x) == getp(f[x]) ? f[x]: x);
			}
		}
		if (!target) root = x;
	}
	void print(int x) const {
		if (ch[x][0]) print(ch[x][0]);
		printf("%d ", data[x]);
		if (ch[x][1]) print(ch[x][1]);
	}
public:
	inline void insert(int x) {
		int now = root;
		while (ch[now][data[now] < x])
			now = ch[now][data[now] < x];
		data[++sz] = x;
		f[sz] = now;
		if(root) ch[now][data[now] < x] = sz;
		ch[sz][0] = ch[sz][1] = 0;
		splay(sz, 0);
	}
	inline void print() const { print(root); }
};
Splay s;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		s.insert(x);
	}
	s.print();
	return 0;
}